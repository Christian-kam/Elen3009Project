/**
 * @class Bullet
 * @author Catherine Honegger and Christian Kamwangala 
 * @date 02/10/2015
 * @file Bullet.h
 * @brief This class captures the abstraction of a bullet object in the game.
 */
#ifndef BULLET_H
#define BULLET_H

#include "DataTypes.h"
#include "Entity.h"

class Bullet : public Entity
{
public:

	/**
	 * @brief Default Constructor.
	 * @details Creates an instance of Bullet and sets all the relevant attributes.
	 * @param position is the initial position of the bullet.
	 */
	Bullet(vector2d position);

	/**
	 * @brief This function returns the speed of the Bullet object.
	 * @return The speed.
	 */
	const float getSpeed() const;

private:
	
	static ID _id;
	static vector2d _bulletSize;

	float _bulletSpeed;
	static objectProperties info;
	
};

#endif

