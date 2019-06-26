#include "GamePresenter.h"

GamePresenter::GamePresenter(const std::shared_ptr<ResourcesHolder> resourcesHolder)
:_resourcesHolder(resourcesHolder)
,_scoreManager(new Score())
,_gameLogic(new Logic(_scoreManager))
,_AImoveTimer(sf::seconds(0.05f))
,_shootAItimer(sf::seconds(3.0f))
,_landerTimer(sf::seconds(7.5f))
,_powerUptime(sf::seconds(4.0f))
,_remainingLanders{_gameLogic->getMax()}
{
	playerStatus = _gameLogic->isActive(ID::playerShip,0);
}

GamePresenter::~GamePresenter()
{
	_gameLogic.reset();
	_resourcesHolder.reset();
}

void GamePresenter::updatePlayerLogic(Direction dir)
{
	_gameLogic->move(dir);
	_movement = dir;
}

void  GamePresenter::updateGame(Sprite& player, std::vector<Sprite>& landers, std::vector<Sprite>& lasers, std::vector<Sprite>& missiles, std::vector<Sprite>& powerUp,std::vector<Sprite>& heatMissiles)
{    
	if(_landerClock.getElapsedTime() > _landerTimer &&  (_gameLogic->getNumberLanders() < _gameLogic->getMax()) && (landers.size() < 6))
	{
		createSprite(landers, ID::lander);
		if(!_gameLogic->isPowerUp() && _gameLogic->getNumberPowerUp()<1)
		{
			createSprite(powerUp, ID::powerUp);
			_powerUpclock.restart();
		}
		_landerClock.restart();
	}
	
	if(_powerUpclock.getElapsedTime() > _powerUptime)
	{
		_gameLogic->destroyPowerUp();
	}
	
	if(_shoot && _gameLogic->isPowerUp() && _gameLogic->getNumberLanders() != 0)
	{
		createSprite(heatMissiles, ID::playerMissile);
		_shoot = false;
	}
	else if(_shoot && _gameLogic->isActive(ID::playerShip,0) && !_gameLogic->isPowerUp())
	{
		{
			createSprite(lasers, ID::playerLaser);
			_shoot = false;
		}
	}
	
	if(_movement == Direction::left)
	{
		player.setRotation(180);
		for (auto& laser: lasers)
			laser.setRotation(180);

		for (auto& heatMissile: heatMissiles)
			heatMissile.setRotation(0);
	}
	else if(_movement == Direction::right)
	{
		player.setRotation(0);
		for (auto& laser: lasers)
		   laser.setRotation(0);
		   
		for (auto& heatMissile: heatMissiles)
			heatMissile.setRotation(180);
	}
	
	if(_AImoveClock.getElapsedTime() > _AImoveTimer)
	 {
		_gameLogic->moveAI();
		_AImoveClock.restart();
	}
    
	if(landers.size()>0)
	{
		if(_shootAIclock.getElapsedTime() > _shootAItimer)
		{
			createSprite(missiles, ID::landerMissile);
			_shootAIclock.restart();
		}
		_gameLogic->shootAI();
	}
	_gameLogic->shoot();
	updateSprites(player,landers,lasers,missiles,powerUp,heatMissiles);
}

void GamePresenter::updateSprites(Sprite& player, std::vector<Sprite>& landers, std::vector<Sprite>& lasers, std::vector<Sprite>& missiles, std::vector<Sprite>& powerUp,std::vector<Sprite>& heatMissiles)
{
	player.setOrigin(_gameLogic->getProperties(ID::playerShip,0).ObjectSize.x/2,_gameLogic->getProperties(ID::playerShip,0).ObjectSize.y/2);
	player.setPosition(_gameLogic->getPosition(ID::playerShip,0).x,_gameLogic->getPosition(ID::playerShip,0).y);
	
	updateStatus(landers, ID::lander);
	updatePosition(landers, ID::lander);
   
	updateStatus(missiles, ID::landerMissile);
	updatePosition(missiles, ID::landerMissile);

	updateStatus(lasers, ID::playerLaser);
	updatePosition(lasers, ID::playerLaser);
	
	updateStatus(powerUp, ID::powerUp);
	updatePosition(powerUp, ID::powerUp);
	
	updateStatus(heatMissiles, ID::playerMissile);
	updatePosition(heatMissiles, ID::playerMissile);
}

void GamePresenter::updatePosition(std::vector<Sprite>& sprites,  ID _entityId)
{
	auto count = 0;
	for (auto& sprite : sprites)
	{
		sprite.setPosition(_gameLogic->getPosition(_entityId,count).x,_gameLogic->getPosition(_entityId,count).y);
		++count;
	}
}

void GamePresenter::updateStatus(std::vector<Sprite>& entities, ID _entityId)
{
	switch(_entityId)
	{
		case ID::lander:
		{
			while(_gameLogic->getNumberLanders() < entities.size()){
				entities.pop_back();
			_remainingLanders--;}
		}
			break;
		case ID::playerLaser:
		{
			while(_gameLogic->getNumberLasers() < entities.size())
				entities.pop_back();
		}
			break;
		case ID::landerMissile:
		{
			while(_gameLogic->getNumberLanderBullets() < entities.size())
				entities.pop_back();
		}
			break;
		case ID::powerUp:
		{
			while(_gameLogic->getNumberPowerUp() < entities.size())
				entities.pop_back();
		}
			break;
		case ID::playerMissile:
		{
			while(_gameLogic->getNumberHeatMissiles() < entities.size())
				entities.pop_back();
		}
			break;
		default:
		;
	}
}

void GamePresenter::createSprite(std::vector<Sprite>& entities, ID _entityId)
{
	unsigned int count = 0;
	switch(_entityId)
	{
		case ID::playerLaser:
			_gameLogic->createLasers();
			break;
		case ID::lander:
			_gameLogic->populateEnemies();
			count = entities.size();
			break;
		case ID::landerMissile:
			_gameLogic->createEnemyBullet();
			break;
		case ID::powerUp:
			_gameLogic->createPowerUp();
			count = entities.size();
			break;
		case ID::playerMissile:
			_gameLogic->createHeat();
			break;
			
		default:
		;
	}
	
	Sprite entitySprite;
	entitySprite.setTexture(_resourcesHolder->getTexture(_entityId));
	
	// Pass the size of the vector lasers to map the sprite
	entitySprite.setPosition(_gameLogic->getPosition(_entityId,count).x,_gameLogic->getPosition(_entityId,count).y);
	 entitySprite.setOrigin(_gameLogic->getProperties(_entityId,count).ObjectSize.x/2,_gameLogic->getProperties(_entityId,count).ObjectSize.y/2);
	entities.push_back(entitySprite);    
}

void GamePresenter::shoot(bool shoot)
{
	_shoot = shoot;
}

bool GamePresenter::getStatus()
{
	if(_gameLogic->isActive(ID::playerShip,0) && _remainingLanders > 0)
		return true;
	else
	{
		_scoreManager->WriteScore();
		return false;
	}
}

unsigned int GamePresenter::getRemainingLanders()
{
	return _remainingLanders;

}

int GamePresenter::getLives()
{
	return _gameLogic->getPlayerLives();
}

const unsigned int GamePresenter::getCurrentScore() const
{
	return _scoreManager->getScore();
}

const unsigned int GamePresenter::getTopScore() const
{
	return _scoreManager->getHighScore();
}

void GamePresenter::smart()
{
	if(!_gameLogic->isPowerUp())
		_gameLogic->activateSmart();
}

unsigned int GamePresenter::getNumSmart()
{
	return _gameLogic->getnumberofSmartBombs();
}

bool GamePresenter::isTopScore()
{
	if(_scoreManager->getScore() > _scoreManager->getHighScore())
		return true;
	else
		return false;
}

