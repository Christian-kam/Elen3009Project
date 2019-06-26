/**
 * @class GamePresenter
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file GamePresenter.h
 * @brief This class captures the abstraction of the presenter in the MVP pattern.
 */

#ifndef GAMEPRESENTER_H
#define GAMEPRESENTER_H

#include "DataTypes.h"
#include "SfmlDataTypes.h"
#include "Logic.h"
#include "Score.h"
#include "ResourcesHolder.h"

class GamePresenter
{
public:

	/**
	 * @brief Default constructor.
	 * @param resourcesHolder a shared pointer of type ResourcesHolder.
	 */
	GamePresenter(const std::shared_ptr<ResourcesHolder> resourcesHolder);
	
	/**
	 * @brief Destructor.
	 * @details Releases all resources used by GamePresenter.
	 */
	~GamePresenter();
	
	/**
	 * @brief This function updates the player's movement.
	 * @param dir is the specified direction.
	 */
	void updatePlayerLogic(Direction dir);
	
	/**
	 * @brief This function takes in different sprite objects and updates their properties by matching them to the logic's data.
	 * @param player is the sprite that represents the player's ship.
	 * @param landers is a vector of sprites representing the landers.
	 * @param lasers is a vector of sprites for the player's laser.
	 * @param missiles is a vector of sprites for the landers' missiles.
	 * @param powerUp is a vector of sprites for the power up.
	 * @param heatMissiles is a vector of sprites to represent the heat seeking missiles.
	 */
	void  updateGame(Sprite& player, std::vector<Sprite>& landers, std::vector<Sprite>& lasers, std::vector<Sprite>& missiles, std::vector<Sprite>& powerUp,std::vector<Sprite>& heatMissiles);
	
	/**
	 * @brief This function activates the shooting ability of the player.
	 * @param shoot is a boolean used to activates the player's shooting capabilties.
	 */
	void shoot(bool shoot);
	
	/**
	 * @brief This function activates the player's smart bombs capabilities.
	 */
	void smart();
	
	/**
	 * @brief Get the game status.
	 * @details This function returns true if the player has been killed or all landers have been destroyed.
	 * @return The status.
	 */
	bool getStatus();
	 
	 /**
	  * @brief This function returns true if a new top score has been achieved, false otherwise.
	  * @return bool.
	  */
	bool isTopScore();
	
	/**
	 * @brief Get the number of remaining landers.
	 * @details This function returns the number of remaining landers in the game.
	 * @return Remaining landers.
	 */
	unsigned int getRemainingLanders();
	
	/**
	 * @brief Get lives.
	 * @details This function returns the number of lives that the player has.
	 * @return Number of lives.
	 */
	int getLives();
	
	/**
	 * @brief Get the current score.
	 * @details This function returns the current score during the gameplay.
	 * @return Current score.
	 */
	const unsigned int getCurrentScore() const;
	
	/**
	 * @brief Get the top score.
	 * @details This function returns the current top score.
	 * @return The top score.
	 */
	const unsigned int getTopScore() const;
	
	/**
	 * @brief Get number of smart bombs.
	 * @details This function returns the number of smart bombs that the player currently has.
	 * @return Number of smart bombs.
	 */
	unsigned int getNumSmart();
	
private:

	std::shared_ptr<ResourcesHolder> _resourcesHolder;
	std::shared_ptr<Score> _scoreManager;
	std::unique_ptr<Logic> _gameLogic;
	Clock _AImoveClock;
	Clock _shootAIclock;
	Clock _landerClock;
	Clock _powerUpclock;
	Time _AImoveTimer;
	Time _shootAItimer;
	Time _landerTimer;
	Time _powerUptime;
	Direction _movement;
	bool _shoot;
	void updateSprites(Sprite& player, std::vector<Sprite>& landers, std::vector<Sprite>& lasers, std::vector<Sprite>& missiles, std::vector<Sprite>& powerUp,std::vector<Sprite>& heatMissiles);
	void updatePosition(std::vector<Sprite>& sprites,  ID _entityId);
	void updateStatus(std::vector<Sprite>& entities, ID _entityId);
	void createSprite(std::vector<Sprite>& entities, ID _entityId);
	bool playerStatus;
	unsigned int _remainingLanders;

};

#endif


