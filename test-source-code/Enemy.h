/**
 * @class Enemy
 * @author Catherine Honegger and Christian Kamwangala 
 * @date 02/10/2015
 * @file Enemy.h
 * @brief This class captures the abstraction of a lander object in the game.
 */
 
#ifndef ENEMY_H
#define ENEMY_H

#include "DataTypes.h"
#include "Entity.h"
#include "StopWatch.h"

class Enemy : public Entity
{
public:
	
	/**
	 * @brief Default Constructor. 
	 * @details Creates an instance of Enemyship and sets all the relevant attributes.
	 * @param position is the initial position of the enemy.
	 */
	Enemy(vector2d position);
	
	/**
	 * @brief Get the current direction.
	 *@details This function returns the current direction of the enemyship.
	 * @return current direction.
	 */
	virtual const int getCurrentDir() const override;
	
	/**
	 * @brief Get the time passed.
	 * @details This function returns the time that has passed since the enemy's last movement.
	 * @return time elapsed.
	 */
	virtual const float getTimePassed() override;
	
	/**
	 * @brief Set the current direction.
	 * @details This function sets the direction of the enemyship.
	 * @param dir is an integer between 1 and 4 that represents the direction.
	 */
	virtual void setCurrentDir(int dir);
	
	/**
	 * @brief Resets the stopwatch.
	 * @details This function puts the time counter back to zero.
	 */
	virtual void resetTime();
	
	/**
	 * @brief This function returns the speed of the enemyship.
	 * @return The ship's speed .
	 */
	const float getSpeed() const;

private:
	static ID _id;
	static vector2d _enemySize;
	int current_direction;
	float _enemySpeed;
	static objectProperties info;
	StopWatch timer;
	
};

#endif