/**
 * @class EnemyBullet
 * @author Catherine Honegger and Christian Kamwangala
 * @date 02/10/2015
 * @file EnemyBullet.h
 * @brief This class captures the abstraction of an Enemy bullet object in the game.
 */

#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "DataTypes.h"
#include "Entity.h"

class EnemyBullet : public Entity
{
public:
	/**
	* @brief Default constructor.
	* @param startPos is the bullet's starting position.
	* @param targetPos is the target's current position.
	*/
	EnemyBullet(vector2d startPos, const vector2d& targetPos);
	
	/**
	 * @brief Get the speed.
	 * @details This function returns the speed of the bullet.
	 * @return Bullet's speed.
	 */
	const float getSpeed() const;
	
	/**
	 * @brief Get the velocity.
	 * @details This function overrides the base class function. It returns the velocity of the bullet.
	 * @return The velocity.
	 */
	const float getVelocity() const override;
	
	/**
	 * @brief Get the direction of the target.
	 * @details This function returns the target's position. It overrides the base class function.
	 * @return Target's direction.
	 */
	const Direction getTargetDirection() override;
	
private:
	static ID _id;
	static vector2d _bulletSize;
	float _bulletSpeed;
	float _velocity; 
	vector2d _targetPos;
	vector2d _startPos;
	static objectProperties info;
};

#endif

