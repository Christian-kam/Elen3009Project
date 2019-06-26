//Catherine Honegger and Christian Kamwangala
//
#include "Bullet.h"
#include "CollisionDetection.h"
#include "Controller.h"
#include "DataTypes.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Entity.h"
#include "HeatSeek.h"
#include "Logic.h"
#include "PlayerShip.h"
#include "PowerUP.h"
#include "Score.h"
#include "StopWatch.h"
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gmockclasses.h"

//**************BULLET**********************
TEST(Bullet, DefaultConstructorWorks)
{
	auto laser = std::make_shared<Bullet>(Bullet ({52,71}));
	vector2d pos = {52,71};
	vector2d size = {15,4};
	EXPECT_TRUE(pos== laser ->getPosition());
	EXPECT_EQ(ID::playerLaser, laser->getObjectProperties().identifier);
	EXPECT_TRUE(size== laser ->getObjectProperties().ObjectSize);
}

TEST(Bullet, getSpeedWorks)
{
	Bullet laser({52,71});
	EXPECT_EQ(25, laser.getSpeed());
}

//**************COLLISIONDETECTION**********************
TEST(CollisionDetection, isCollideTrueWhenCollides)
{
	auto laser = std::make_shared<Bullet>(Bullet ({52,71}));
	auto lander = std::make_shared<Enemy>(Enemy({52,71}));
	CollisionDetection Collision(lander, laser);
	EXPECT_TRUE(Collision.isColide());
}

TEST(CollisionDetection, isCollideFalseWhenDoesntCollide)
{
	auto laser = std::make_shared<Bullet>(Bullet ({52,71}));
	auto lander = std::make_shared<Enemy>(Enemy({300,71}));
	CollisionDetection Collision(laser, lander);
	EXPECT_FALSE(Collision.isColide());
}

//**************CONTROLLER**********************
TEST(Controller, getEntityWorks)
{
	auto laser = std::make_shared<Bullet>(Bullet ({52,71}));
	Controller controller(laser);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {52,71};
	vector2d size = {15,4};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
	EXPECT_EQ(ID::playerLaser, ControllerEntity ->getObjectProperties().identifier);
	EXPECT_TRUE(size== ControllerEntity ->getObjectProperties().ObjectSize);
}

TEST(Controller, moveEntityUpWorks)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({100,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::up);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {100,(200-ship->getSpeed())};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityDownWorks)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({100,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::down);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {100,(200+ship->getSpeed())};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityLeftWorks)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({100,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::left);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {(100-ship->getSpeed()),200};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityRightWorks)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({100,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::right);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {(100+ship->getSpeed()),200};
	EXPECT_TRUE(pos == ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityRandomABounded)
{
	auto lander= std::make_shared<Enemy>(Enemy({200,500}));
	Controller controller(lander);
	controller.moveEntity(Direction::randomA);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(30, ControllerEntity ->getPosition().x);
	EXPECT_GE(3550, ControllerEntity ->getPosition().x);
	EXPECT_LE(150, ControllerEntity ->getPosition().y);
	EXPECT_GE(545, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionLeftWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({100,500});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(100, ControllerEntity ->getPosition().x);
	EXPECT_GE(200, ControllerEntity ->getPosition().x);
	EXPECT_FLOAT_EQ(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionRightWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({300,500});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(200, ControllerEntity ->getPosition().x);
	EXPECT_GE(300, ControllerEntity ->getPosition().x);
	EXPECT_FLOAT_EQ(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionUpWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({200,400});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_FLOAT_EQ(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(400, ControllerEntity ->getPosition().y);
	EXPECT_GE(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionDownWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({200,600});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_FLOAT_EQ(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(500, ControllerEntity ->getPosition().y);
	EXPECT_GE(600, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionUpLeftWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({100,400});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(100, ControllerEntity ->getPosition().x);
	EXPECT_GE(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(400, ControllerEntity ->getPosition().y);
	EXPECT_GE(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionUpRightWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({100,600});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(100, ControllerEntity ->getPosition().x);
	EXPECT_GE(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(500, ControllerEntity ->getPosition().y);
	EXPECT_GE(600, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionDownLeftWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({300,400});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(200, ControllerEntity ->getPosition().x);
	EXPECT_GE(300, ControllerEntity ->getPosition().x);
	EXPECT_LE(400, ControllerEntity ->getPosition().y);
	EXPECT_GE(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityPositionDownRightWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek({200,500}));
	Controller controller(heatMissile);
	controller.moveEntity({200,600});
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(200, ControllerEntity ->getPosition().x);
	EXPECT_GE(300, ControllerEntity ->getPosition().x);
	EXPECT_LE(500, ControllerEntity ->getPosition().y);
	EXPECT_GE(600, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityToTargetUpLeftWorks)
{
	auto landerMissile = std::make_shared<EnemyBullet> (EnemyBullet({200,500},{100,400}));
	Controller controller(landerMissile);
	controller.moveEntity();
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(100, ControllerEntity ->getPosition().x);
	EXPECT_GE(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(400, ControllerEntity ->getPosition().y);
	EXPECT_GE(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityToTargetUpRightWorks)
{
	auto landerMissile = std::make_shared<EnemyBullet> (EnemyBullet({200,500},{100,600}));
	Controller controller(landerMissile);
	controller.moveEntity();
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(100, ControllerEntity ->getPosition().x);
	EXPECT_GE(200, ControllerEntity ->getPosition().x);
	EXPECT_LE(500, ControllerEntity ->getPosition().y);
	EXPECT_GE(600, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityToTargetDownLeftWorks)
{
	auto landerMissile = std::make_shared<EnemyBullet> (EnemyBullet({200,500},{300,400}));
	Controller controller(landerMissile);
	controller.moveEntity();
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(200, ControllerEntity ->getPosition().x);
	EXPECT_GE(300, ControllerEntity ->getPosition().x);
	EXPECT_LE(400, ControllerEntity ->getPosition().y);
	EXPECT_GE(500, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityToTargetDownRightWorks)
{
	auto landerMissile = std::make_shared<EnemyBullet> (EnemyBullet({200,500},{300,600}));
	Controller controller(landerMissile);
	controller.moveEntity();
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	EXPECT_LE(200, ControllerEntity ->getPosition().x);
	EXPECT_GE(300, ControllerEntity ->getPosition().x);
	EXPECT_LE(500, ControllerEntity ->getPosition().y);
	EXPECT_GE(600, ControllerEntity ->getPosition().y);
}

TEST(Controller, moveEntityLeftBoundedDoesntMove)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({0,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::left);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {0,200};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityRightBoundedDoesntMove)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({3940,200}));
	Controller controller(ship);
	controller.moveEntity(Direction::right);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {3940,200};
	EXPECT_EQ(pos.x,ControllerEntity ->getPosition().x);
}

TEST(Controller, moveEntityUpBoundedDoesntMove)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({600,150}));
	Controller controller(ship);
	controller.moveEntity(Direction::up);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {600,150};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

TEST(Controller, moveEntityDownBoundedDoesntMove)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip({600,580}));
	Controller controller(ship);
	controller.moveEntity(Direction::down);
	std::shared_ptr<Entity> ControllerEntity = controller.getEntity();
	vector2d pos = {600,580};
	EXPECT_TRUE(pos== ControllerEntity ->getPosition());
}

//**************ENEMY**********************
TEST(Enemy, DefaultConstructorWorks)
{
	auto lander = std::make_shared<Enemy> (Enemy({100,200}));
	vector2d pos = {100,200};
	vector2d size = {23,23};
	EXPECT_TRUE(pos== lander->getPosition());
	EXPECT_EQ(ID::lander, lander->getObjectProperties().identifier);
	EXPECT_TRUE(size== lander->getObjectProperties().ObjectSize);
}

TEST(Enemy, getCurrentDirWorks)
{
	Enemy lander({100,200});
	EXPECT_GE(4, lander.getCurrentDir());
}

TEST(Enemy, setCurrentDirWorks)
{
	Enemy lander({100,200});
	lander.setCurrentDir(2);
	EXPECT_EQ(2,lander.getCurrentDir());
}

TEST(Enemy, getSpeedWorks)
{
	Enemy lander({52,71});
	EXPECT_EQ(2.5, lander.getSpeed());
}

TEST(Enemy, getTimeWorks)
{
	Enemy lander({52,71});
	EXPECT_GE(0, lander.getTimePassed());
}

TEST(Enemy, resetTimeWorks)
{
	Enemy lander({52,71});
	lander.resetTime();
	EXPECT_EQ(0, lander.getTimePassed());
}

//**************ENEMYBULLET**********************
TEST(EnemyBullet, DefaultConstructorWorks)
{
	auto missile = std::make_shared<EnemyBullet> (EnemyBullet({52,71}, {100,200}));
	vector2d pos = {52,71};
	vector2d size = {3,3};
	EXPECT_TRUE(pos== missile->getPosition());
	EXPECT_EQ(ID::landerMissile, missile->getObjectProperties().identifier);
	EXPECT_TRUE(size== missile->getObjectProperties().ObjectSize);
}

TEST(EnemyBullet, getSpeedWorks)
{
	EnemyBullet missile({52,71}, {100,200});
	EXPECT_EQ(3, missile.getSpeed());
}

TEST(EnemyBullet, getTargetDirectionDiagonallyUpRightWorks)
{
	EnemyBullet missile({52,71}, {100,20});
	EXPECT_TRUE(Direction::diagonalUpRight == missile.getTargetDirection());
}

TEST(EnemyBullet, getTargetDirectionDiagonallyUpLeftWorks)
{
	EnemyBullet missile({52,71}, {10,20});
	EXPECT_TRUE(Direction::diagonalUpLeft == missile.getTargetDirection());
}

TEST(EnemyBullet, getTargetDirectionDiagonallyDownLeftWorks)
{
	EnemyBullet missile({52,71}, {10,200});
	EXPECT_TRUE(Direction::diagonalDownLeft == missile.getTargetDirection());
}

TEST(EnemyBullet, getTargetDirectionDiagonallyDownRightWorks)
{
	EnemyBullet missile({52,71}, {100,200});
	EXPECT_TRUE(Direction::diagonalDownRight == missile.getTargetDirection());
}

//**************ENTITY**********************
TEST(Entity, getPositionWorks)
{
	PlayerShip ship({100,200});
	ship.getPosition();
	vector2d pos = {100,200};
	EXPECT_TRUE(pos == ship.getPosition());
}

TEST(Entity, getObjectPropertiesWorks)
{
	PlayerShip ship({100,200});
	vector2d size = {65,65};
	EXPECT_EQ(ID::playerShip, ship.getObjectProperties().identifier);
	EXPECT_TRUE(size==ship.getObjectProperties().ObjectSize);
}

TEST(Entity, setPositionWorks)
{
	PlayerShip ship({100,200});
	ship.setPosition({500,72});
	vector2d pos = {500,72};
	EXPECT_TRUE(pos == ship.getPosition());
}

TEST(Entity, getRotationWorks)
{
	PlayerShip ship({100,200});
	EXPECT_EQ(180, ship.getRotation());
}

TEST(Entity, setRotationWorks)
{
	PlayerShip ship({100,200});
	ship.setRotation(72);
	EXPECT_EQ(72, ship.getRotation());
}

TEST(Entity, isActiveWhenEnemyAlive)
{
	Enemy lander({100,200});
	EXPECT_TRUE(lander.isActive());
}

TEST(Entity, notActiveWhenEnemyKilled)
{
	Enemy lander({100,200});
	lander.whenKilled();
	EXPECT_FALSE(lander.isActive());
}

TEST(Entity, getCurrentDirWorks)
{
	PlayerShip ship({100,200});
	EXPECT_EQ(0,ship.getCurrentDir());
}

TEST(Entity, getTimePassedWorks)
{
	PlayerShip ship({100,200});
	EXPECT_EQ(0,ship.getTimePassed());
}

TEST(Entity, getTargetDirectionWorks)
{
	PlayerShip ship({100,200});
	EXPECT_EQ(Direction::up, ship.getTargetDirection());
}

TEST(Entity, getVelocityWorks)
{
	PlayerShip ship({100,200});
	EXPECT_EQ(0, ship.getVelocity());
}

//**************HEATSEEK**********************
TEST(HeatSeek, DefaultConstructorWorks)
{
	auto heatMissile = std::make_shared<HeatSeek>(HeatSeek ({52,71}));
	vector2d pos = {52,71};
	vector2d size = {17,4};
	EXPECT_TRUE(pos== heatMissile ->getPosition());
	EXPECT_EQ(ID::playerMissile, heatMissile->getObjectProperties().identifier);
	EXPECT_TRUE(size== heatMissile ->getObjectProperties().ObjectSize);
}

TEST(HeatSeek, getSpeedWorks)
{
	HeatSeek heatMissile({52,71});
	EXPECT_EQ(5, heatMissile.getSpeed());
}

//**************LOGIC**********************

TEST(Logic, defaultConstructorWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	vector2d pos = {1600,200};
	EXPECT_TRUE( pos == _logic.getPosition(ID::playerShip, 0));
	unsigned int max = 10;
	EXPECT_EQ(max, _logic.getMax());
	EXPECT_EQ(6, _logic.getPlayerLives());
	unsigned int smart = 3;
	EXPECT_EQ(smart, _logic.getnumberofSmartBombs());
}

TEST(Logic, getNumberLandersWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberLanders());
}

TEST(Logic, populateEnimiesWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.populateEnemies();
	unsigned int number = 1;
	EXPECT_EQ(number, _logic.getNumberLanders());
}

TEST(Logic, getNumberLasersWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberLasers());
}

TEST(Logic, createLasersWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.createLasers();
	unsigned int number = 1;
	EXPECT_EQ(number, _logic.getNumberLasers() );
}

TEST(Logic, getNumberLanderBulletsWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberLanderBullets());
}

TEST(Logic, createEnemyBulletWorksWithEnemy)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.populateEnemies();
	_logic.createEnemyBullet();
	unsigned int number = 1;
	EXPECT_EQ(number, _logic.getNumberLanderBullets());
}

TEST(Logic, createEnemyBulletDoesntWorkWithoutEnemy)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.createEnemyBullet();
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberLanderBullets());
}

TEST(Logic, createPowerUpWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.createPowerUp();
	unsigned int number = 1;
	EXPECT_EQ(number, _logic.getNumberPowerUp());
}

TEST(Logic, getNumberPowerUpWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberPowerUp());
}

TEST(Logic, createHeatDoesntWorkIfNoPowerUp)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	_logic.createHeat();
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberHeatMissiles() );
}

TEST(Logic, getNumberHeatMissilesWorks)
{
	auto score = std::make_shared<Score>(Score());
	Logic _logic(score);
	unsigned int number = 0;
	EXPECT_EQ(number, _logic.getNumberHeatMissiles());
}
//TEST(Logic, getPlayerLivesWorks)
//{
//	PlayerShipMock mockShip({100,200});
//	Logic logic;
//	EXPECT_CALL(mockShip, getLives())
//		.Times(6);
//		.WillOnce(testing::Return(6))
//		.WillOnce(testing::Return(5))
//		.WillOnce(testing::Return(4))
//		.WillOnce(testing::Return(3))
//		.WillOnce(testing::Return(2))
//		.WillOnce(testing::Return(1));
//}

//**************PLAYERSHIP**********************
TEST(PlayerShip, DefaultConstructorWorks)
{
	auto ship = std::make_shared<PlayerShip>(PlayerShip ({52,71}));
	vector2d pos = {52,71};
	vector2d size = {65,65};
	EXPECT_TRUE(pos== ship ->getPosition());
	EXPECT_EQ(ID::playerShip, ship->getObjectProperties().identifier);
	EXPECT_TRUE(size== ship ->getObjectProperties().ObjectSize);
	EXPECT_EQ(180, ship->getRotation());
}

TEST(PlayerShip, getSpeedWorks)
{
	PlayerShip ship({52,71});
	EXPECT_EQ(30, ship.getSpeed());
}

TEST(PlayerShip, getLivesWithoutDyingWorks)
{
	PlayerShip ship({52,71});
	EXPECT_EQ(6, ship.getLives());
}

TEST(PlayerShip, LivesDecreaseWhenKilled)
{
	PlayerShip ship({52,71});
	int lives = ship.getLives();
	ship.whenKilled();
	EXPECT_EQ(lives-1, ship.getLives());
}

//**************POWERUP**********************
TEST(PowerUp, DefaultConstructorWorks)
{
	auto powerUp = std::make_shared<PowerUp>(PowerUp ({52,71}));
	vector2d pos = {52,71};
	vector2d size = {67,49};
	EXPECT_TRUE(pos== powerUp ->getPosition());
	EXPECT_EQ(ID::powerUp, powerUp->getObjectProperties().identifier);
	EXPECT_TRUE(size== powerUp ->getObjectProperties().ObjectSize);
}

TEST(PowerUp, getSpeedWorks)
{
	PowerUp powerUp({52,71});
	EXPECT_EQ(3, powerUp.getSpeed());
}
//**************SCORE**********************

TEST(Score, defaultConstructorWorks)
{
	Score score;
	EXPECT_EQ(0, score.getScore());
}

TEST(Score, updateLanderWorks)
{
	Score score;
	score.updateScore(ID::lander);
	EXPECT_EQ(150, score.getScore());
}

TEST(Score, updatePowerUpWorks)
{
	Score score;
	score.updateScore(ID::powerUp);
	EXPECT_EQ(1000, score.getScore());
}

TEST(Score, updatePlayerSmartBombWorks)
{
	Score score;
	score.updateScore(ID::playerSmartBomb);
	EXPECT_EQ(500, score.getScore());
}

TEST(Score, getScoreWorks)
{
	Score score;
	score.updateScore(ID::lander);
	score.updateScore(ID::lander);
	EXPECT_EQ(300, score.getScore());
}

TEST(Score, getHighScoreWorks)
{
	Score score;
	EXPECT_LE(0, score.getHighScore());
}

TEST(Score, WriteScoreWorks)
{
	Score score;
	score.updateScore(ID::lander);
	score.updateScore(ID::powerUp);
	score.updateScore(ID::powerUp);
	score.WriteScore();
	Score score2;
	EXPECT_LE(2150, score2.getHighScore());
}

//**************STOPWATCH**********************
TEST(StopWatch, startWorks)
{
	StopWatch clock;
	clock.start();
	EXPECT_GE(0,clock.stop());
}
