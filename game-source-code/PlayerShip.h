/**
 * @class PlayerShip
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file PlayerShip.h
 * @brief This class models the player ship object in the game.
 */
#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "DataTypes.h"
#include "Entity.h"

class PlayerShip : public Entity
{
public:
	/**
	 * @brief Default constructor.
	 * @param position contains the x and y coordinates of the player's position.
	 */
	PlayerShip(vector2d position);

	/**
	 * @brief This function marks the player as inactive when he is killed in the game.
	 * It overrides the base class function given that the player has more than one life.
	 */
	virtual void whenKilled() override;
	
	/**
	 * @brief Get the speed.
	 * @details This function returns the speed of the player's ship.
	 * @return The playership's speed.
	 */
	virtual const float getSpeed() const;
	
	/**
	 * @brief Get the lives.
	 * @details This function returns the number of lives that the player has.
	 * @return The number of lives.
	 */
	const int getLives() const;

private:
	int _lives;
	static ID _id;
	static vector2d _playerSize;
	float _playerSpeed;
	static objectProperties info;
};
#endif
