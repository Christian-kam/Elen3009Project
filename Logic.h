/**
 * @class Logic
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file Logic.h
 * @brief This class contains the main logic of the game.
 */
#ifndef LOGIC_H
#define LOGIC_H

#include "DataTypes.h"
#include "Entity.h"
#include "Controller.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "PlayerShip.h"
#include "CollisionDetection.h"
#include "PowerUP.h"
#include "HeatSeek.h"
#include "Score.h"

class Logic
{
public:

	/**
	* @brief Default constructor.
	* @details Creates an instance of the class.
	* @param scoreManager is a shared pointer of Score type.
	*/
	Logic(std::shared_ptr<Score> scoreManager);
	
	/**
	 * @brief Destructor.
	 * @details Releases all resources used by Logic.
	 */
	~Logic();
	
	/**
	 * @brief Move.
	 * @details This function is reponsible for updating the movement of the PlayerShip object.
	 * @param dir specifies the direction of movement.
	 */
	void move(Direction dir);
	
	/**
	 * @brief Move the AI.
	 * @details This function is reponsible for the movement of all Enemy objects.
	 */
	void moveAI();
	
	/**
	 * @brief Shoot.
	 * @details This function controls the shoot of the PlayerShip object.
	 */
	void shoot();
	
	/**
	 * @brief AI shooting.
	 * @details This function controls the shooting of the Enemy objects.
	 */
	void shootAI();
	
	/**
	 * @brief Power up activated.
	 * @details This function returns true if the Player has picked up a power up, false otherwise.
	 * @return bool.
	 */
	bool isPowerUp();
	
	/**
	 * @brief Shoot the heat seeking missiles.
	 * @details This function controls the shooting of heat-seeking missiles.
	 */
	void shootHeatSeeking();
	
	/**
	 * @brief This functions returns true if the object is active, false otherwise.
	 * @param id identifies the object being queried.
	 * @param objectPos is the index of the object in a vector. It is set to zero if the object is not in a vector.
	 * @return bool.
	 */
	bool isActive(ID id, int objectPos);
	
	/**
	 * @brief Get the position.
	 * @details This function returns the position of the object.
	 * @param id identifies the object being queried.
	 * @param objectPos is the index of the object in a vector. It is set to zero if the object is not in a vector.
	 * @return The x and y coordinates of the object's position.
	 */
	vector2d getPosition(ID id, int objectPos);
	
	/**
	 * @brief Get the properties.
	 * @details This function returns the properties of the object.
	 * @param id is used to identify the object being queried.
	 * @param objectPos is the index of the object in a vector. It is set to zero if the object is not in a vector. 
	 * @return The properties of the object. 
	 */
	objectProperties getProperties(ID id, int objectPos);
	
	
	/**
	 * @brief Get the number of landers.
	 * @details This function returns the number of landers currently in the game.
	 * @return The number of landers.
	 */
	const unsigned int getNumberLanders() const;
	
	/**
	 * @brief Get the number of lasers.
	 * @details This function returns the number of lasers object created.
	 * @return The number of lasers.
	 */
	const unsigned int getNumberLasers() const;
	
	/**
	 * @brief Get the number of landers' bullets.
	 * @return The number of enemy bullets created.
	 */
	const unsigned int getNumberLanderBullets() const;
	
	/**
	 * @brief Get the number of power-ups.
	 * @details This function returns the number of power-ups created.
	 * @return Number of power-ups.
	 */
	const unsigned int getNumberPowerUp() const;
	
	/**
	 * @brief Get number of heat missiles.
	 * @details This function returns the number of heat-seeking missiles.
	 * @return Number of heat missiles. 
	 */
	const unsigned int getNumberHeatMissiles() const;
	
	/**
	 * @brief Get maximum.
	 * @details This function returns the maximum number of landers that can be created. 
	 * @return The maximum number of landers.
	 */
	const unsigned int getMax() const;
	
	/**
	 * @brief Get number of smart bombs.
	 * @details This function returns the number of smart bombs available to the player.
	 * @return The number of smart bombs.
	 */
	const unsigned int getnumberofSmartBombs() const;
	
	/**
	 * @brief Get the player's lives.
	 * @details This function returns the number of lives that the player has.
	 * @return The number of lives.
	 */
	const int getPlayerLives() const;
	
	/**
	 * @brief Populate enemies.
	 * @details This function generates a vector of Enemy type. These are the landers in the game.
	 */
	void populateEnemies();
	
	/**
	 * @brief Create lasers.
	 * @details This function creates a vector of Bullet type use for the player's laser.
	 */
	void createLasers();
	
	/**
	 * @brief Create EnemyBullet.
	 * @details This function generates a vector of EnemyBullet type used for the landers' missiles.
	 */
	void createEnemyBullet();
	
	/**
	 * @brief Create power-up.
	 * @details This function creates the PowerUp objects that appears during the game.
	 */
	void createPowerUp();
	
	/**
	 * @brief Create heat.
	 * @details This function is responsible for generating the heat seeking missiles.
	 */
	void createHeat();
	
	/**
	 * @brief Destroy power-up.
	 * @details This function destroys the power-up after a certain time has expired.
	 */
	void destroyPowerUp();
	
	/**
	 * @brief Activate smart.
	 * @details This function activates the player's smart bombs.
	 */
	void activateSmart();

private:
	std::shared_ptr<PlayerShip> _player;
	std::unique_ptr<Controller> _playerController;
	std::shared_ptr<Score> _scoreManager;
	std::vector<std::shared_ptr<Enemy> > _enemies;
	std::vector<std::shared_ptr<Bullet> > _playerLaser;
	std::vector<std::shared_ptr<PowerUp> > _powerUp;
	std::vector<std::shared_ptr<HeatSeek> > _heatSeeking;
	std::vector<std::shared_ptr<EnemyBullet> > _landerBullet;
	
	void checkCollisionPlayerAI(std::vector<std::shared_ptr<Entity> > entities);
	void checkCollisionLaserAI();
	void checkCollisionPlayerPowerUp();
	void checkCollisionHeatAI();
	void respawnPlayer();
	void eraseEnemyKilled();
	
	StopWatch timer;
	bool _specialPower;
	unsigned int _maxNumberofLanders;
	bool _fired;
	unsigned int _firedHeatmissiles;
	int _playerLives;
	unsigned int _smartBombs;
};

#endif


