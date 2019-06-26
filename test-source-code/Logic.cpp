#include "Logic.h"
#include "RandomPositionGen.h"

Logic::Logic(std::shared_ptr<Score> scoreManager)
:_player(new PlayerShip({1600,200}))
,_playerController(new Controller(_player))
,_scoreManager(scoreManager)
,_specialPower{false}
,_maxNumberofLanders{10}
,_fired{false}
,_firedHeatmissiles{0}
,_playerLives{_player->getLives()}
,_smartBombs{3}

{
} // nothing else to do

Logic::~Logic()
{
	_player.reset();
	_playerController.reset();
	timer.start();
}

void Logic::move(Direction dir)
{    
	std::vector<std::shared_ptr<Entity> > _entities;
	_playerController->moveEntity(dir);
	
	for (auto lander : _enemies)
		_entities.push_back(lander);
		
	checkCollisionPlayerAI(_entities);
	_entities.clear();
	
	for (auto missile : _landerBullet)
		_entities.push_back(missile);
		
	checkCollisionPlayerAI(_entities);
	checkCollisionPlayerPowerUp();
}

void Logic::moveAI()
{
	std::vector<std::shared_ptr<Entity> > _entities;
	for (auto lander : _enemies)
	{
		std::unique_ptr<Controller> _AIController(new Controller(lander));
		_AIController->moveEntity(Direction::randomA);
		_entities.push_back(lander);
	}
	
	if(_enemies.size()==0)
	{
		_landerBullet.clear();
	}
	
	checkCollisionPlayerAI(_entities);
	checkCollisionLaserAI();
	checkCollisionHeatAI();
}


vector2d Logic::getPosition(ID id, int objectPos)
{
	switch(id)
	{
		case ID::playerShip:
			return _player->getPosition();
			break;
		case ID::lander:
			return (_enemies.at(objectPos))->getPosition();
			break;
		case ID::playerLaser:
			return (_playerLaser.at(objectPos))->getPosition();
			break;
		case ID::landerMissile:
			return (_landerBullet.at(objectPos))->getPosition();
			break;
		case ID::powerUp:
			return (_powerUp.at(objectPos))->getPosition();
			break; 
		case ID::playerMissile:
			return (_heatSeeking.at(objectPos))->getPosition();
			break;                   
		default:
		;
	}
	return _player->getPosition(); 
}

objectProperties Logic::getProperties(ID id, int objectPos)
{
	switch(id)
	{
		case ID::playerShip:
			return _player->getObjectProperties();
			break;
		case ID::lander:
			return (_enemies.at(objectPos))->getObjectProperties();
			break;
		case ID::playerLaser:
			return (_playerLaser.at(objectPos))->getObjectProperties();
			break;
		case ID::landerMissile:
			return (_landerBullet.at(objectPos))->getObjectProperties();
			break;
		case ID::powerUp:
			return (_powerUp.at(objectPos))->getObjectProperties();
			break;
		case ID::playerMissile:
			return (_heatSeeking.at(objectPos))->getObjectProperties();
			break;                  
		default:
		;
	}
	return _player->getObjectProperties();
}

void Logic::populateEnemies()
{
	vector2d position = randomPositionGen();
	auto lander = std::make_shared<Enemy>(Enemy(position));
	_enemies.push_back(lander);
}

//Fire in the hole
void Logic::shoot()
{    
	if(_player->isActive())
	{
		if(!_specialPower)
		{
			for (auto laser : _playerLaser)
			{
				auto _laserController = std::make_shared<Controller>(Controller(laser));
				
				//get player direction and fire
				
				if((laser->getRotation()) == 180)
					_laserController->moveEntity(Direction::right);
				else
					_laserController->moveEntity(Direction::left);
				
			}
		}
		else if(_specialPower && _heatSeeking.size() != 0)
			shootHeatSeeking();       
	}
}


void Logic::shootAI()
{
	std::vector<std::shared_ptr<Entity> > _entities;
	for (auto missile : _landerBullet)
	{
		auto _missileController = std::make_shared<Controller>(Controller(missile));
		_missileController->moveEntity();
		_entities.push_back(missile); // cast the child into the parent class in order to check for collision
	}
	checkCollisionPlayerAI(_entities);
}

void Logic::createLasers()
{
	auto laser = std::make_shared<Bullet>(Bullet(_player->getPosition()));
	laser->setRotation(_player->getRotation());
	_playerLaser.push_back(laser);
}


void Logic::createEnemyBullet()
{
	auto deltaT = timer.stop();
	if (deltaT > 5)
	{
		_landerBullet.clear();
		timer.reset();
		timer.start();
	}

	for (auto enemy : _enemies)
	{
		auto missile = std::make_shared<EnemyBullet>(EnemyBullet(enemy->getPosition(), _player->getPosition()));
		_landerBullet.push_back(missile);
	}
}

bool Logic::isActive(ID id, int objectPos)
{
	switch(id)
	{
		case ID::playerShip:
			return _player->isActive();
			break;
		case ID::lander:
			if (!(_enemies.at(objectPos))->isActive())
			return (_enemies.at(objectPos))->isActive();
			break;
		case ID::playerLaser:
			return (_playerLaser.at(objectPos))->isActive();
			break;
		case ID::landerMissile:
			return (_landerBullet.at(objectPos))->isActive();
			break;
		case ID::powerUp:
			return (_powerUp.at(objectPos))->isActive();
			break;
		case ID::playerMissile:
			return (_heatSeeking.at(objectPos))->isActive();
			break;
		default:
		;
	}

	return _player->isActive();
}


// collision detection 

void Logic::checkCollisionPlayerAI(std::vector<std::shared_ptr<Entity> > entities)
{
	for (const auto entity : entities)
	{
		std::unique_ptr<CollisionDetection> _collisionDetector(new CollisionDetection(_player, entity));
		if(_collisionDetector->isColide())
		{
			_player->whenKilled();
		   respawnPlayer();
		}
	}
}

void Logic::checkCollisionLaserAI()
{
	auto backgroundRightBound = 3959;
	
	for( auto laser : _playerLaser)
	{
		for (auto lander : _enemies)
		{
			std::unique_ptr<CollisionDetection> _collisionDetector(new CollisionDetection(lander, laser));
			if(_collisionDetector->isColide())
			{
				lander->whenKilled();
				laser->whenKilled();
			   _scoreManager->updateScore(ID::lander);
			}
				
		}
	}
	
	// Loop through the vector of enemies and erase the ones that have been killed
	eraseEnemyKilled();
	
	// Loop through the vector of lasers and erase the ones that have collided with the enemies
	auto iter2 = begin(_playerLaser);
	while (iter2 != end(_playerLaser))
	{
		auto x = (*iter2)->getPosition().x;
	if(!((*iter2)->isActive()) || x <= 1 || x >= backgroundRightBound) // Also delete the laser if out of bounds.
			_playerLaser.erase(iter2);
		else
			iter2++;
	}
}


void Logic::checkCollisionPlayerPowerUp()
{
	for (auto power : _powerUp)
	{
		std::unique_ptr<CollisionDetection> _collisionDetector(new CollisionDetection(_player, power));
		if(_collisionDetector->isColide())
		{
			_powerUp.pop_back();
			_playerLaser.clear();
			_specialPower = true;
			_scoreManager->updateScore(ID::powerUp);

		}
		else
			_specialPower = false;
	}
}

void Logic::checkCollisionHeatAI()
{
	for(auto heatmissile : _heatSeeking)
	{
		for(auto lander : _enemies)
		{
			std::unique_ptr<CollisionDetection> _collisionDetector(new CollisionDetection(lander, heatmissile));
			if(_collisionDetector->isColide()) 
			{
				lander->whenKilled();
				heatmissile->whenKilled();
				_heatSeeking.pop_back();
				_scoreManager->updateScore(ID::lander);
				
				// Check if the number of fired heatmissiles has exceeded the limit
				if(_firedHeatmissiles > 3)
				{
					_specialPower = false;
					_firedHeatmissiles = 0;
				}
				_fired = false;
				
			}
		}
	}
	
	eraseEnemyKilled();           
}

void Logic::createPowerUp()
{
	float x = rand()%3000+370;
	float y = rand()%110+440; 
	auto power = std::make_shared<PowerUp>(PowerUp({x,y}));
	_powerUp.push_back(power);
}

void Logic::createHeat()
{
	
	if(!_fired && _enemies.size() != 0)
	{
	   auto heatmissile = std::make_shared<HeatSeek>(HeatSeek(_player->getPosition()));
		heatmissile->setRotation(_player->getRotation());
		_heatSeeking.push_back(heatmissile);
		
		_fired = true;
		_firedHeatmissiles++;
		
	}
	
}

void Logic::shootHeatSeeking()
{    

	auto playerPos = _player->getPosition();
	vector2d minPos{800,500};
	auto target = -1;
		
	// Search for the closest lander and mark him as the target for the heat-seeking missile
	for(auto lander: _enemies)
	{
		if((playerPos-(lander->getPosition())) < minPos)
			target++;
	}
		
	if(target < 0)
			target = 0;
	for(auto heat:  _heatSeeking)
	{
		auto _targetPosition = (_enemies.at(target))->getPosition();
		std::unique_ptr<Controller> heatController(new Controller(heat));
		heatController->moveEntity(_targetPosition);
	}
}

bool Logic::isPowerUp()
{
	return _specialPower;
	
}

void Logic::respawnPlayer()
{
	_player->setPosition(randomPositionGen());
}

void Logic::destroyPowerUp()
{
	_powerUp.clear();
}

void Logic::activateSmart()
{
	if(_smartBombs > 0)
	{
	_scoreManager->updateScore(ID::playerSmartBomb);
	_enemies.clear();
	_smartBombs--;
	}
}

const unsigned int Logic::getNumberLanders() const
{
	return _enemies.size();
}

const unsigned int Logic::getNumberLasers() const
{
	return _playerLaser.size();
}

const unsigned int Logic::getNumberLanderBullets() const
{
	return _landerBullet.size();
}

const unsigned int Logic::getNumberPowerUp() const
{
	return _powerUp.size();
}
const unsigned int Logic::getNumberHeatMissiles() const
{
	return _heatSeeking.size();
}

const unsigned int Logic::getMax() const
{
	return _maxNumberofLanders;
}

const int Logic::getPlayerLives() const
{
	return _player->getLives();
}

const unsigned int Logic::getnumberofSmartBombs() const
{
	return _smartBombs;
}


void Logic::eraseEnemyKilled()
{
	auto iter1 = begin(_enemies);
	while (iter1 != end(_enemies))
	{
		if(!((*iter1)->isActive()))
			_enemies.erase(iter1);
		else
			iter1++;
	}  
}