/**
 * @class Entity
 * @author Catherine Honegger and Christian Kamwangala
 * @date 02/10/2015
 * @file Entity.h
 * @brief This class captures the abstraction of an Entity in the game.
 * This is the base class from which all other enties inherit.
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "DataTypes.h"

class Entity
{
public:

	/**
	 * @brief Default Constructor. 
	 * @details This constructor is called in the derived class.
	 * @param position is the initial position of the entity.
	 * @param objProps contains the properties of the entity.
	 */
	Entity(vector2d& position, objectProperties& objProps);
	
	/**
	 * @brief Destructor.
	 * @details Ensures that all derived class objects are destroyed.
	 */
	virtual ~Entity();
	
	/**
	 * @brief Set the position.
	 * @details This function sets the position of the entity in the game world.
	 * @param pos contains the x and y coordinates of the position.
	 */
	void setPosition(vector2d pos);
	
	/**
	 * @brief Get the position.
	 * @details This function returns the position of the entity.
	 * @return The position.
	 */
	 
	const vector2d& getPosition() const;
	
	/**
	 * @brief Set the rotation.
	 * @details This function sets the rotation of the entity.
	 * @param rotation in degrees (180 or 0).
	 */
	void setRotation(float rotation);
	
	/**
	 * @brief Get the rotation.
	 * @details This function returns the current rotation of the entity.
	 * @return The entity's rotation.
	 */
	const float getRotation() const;
	
	/**
	 * @brief Get the object's properties.
	 * @details This functions returns the object's properties which includes the identifier and the object's size.
	 * @return The properties of the entity.
	 */
	const objectProperties& getObjectProperties() const;
	
	/**
	 * @brief This function returns true if the entity is active and false otherwise.
	 * @return The status of the entity.
	 */
	bool isActive() const;
	
	/**
	 * @brief Get the speed.
	 * @details This is a pure virtual function that returns the speed of the entity.
	 * @return Speed.
	 */
	virtual const float getSpeed() const = 0;
	
	/**
	 * @brief This function marks the entity as inactive when the entity is killed.
	 */
	virtual void whenKilled();
	
	/**
	 * @brief Get the current direction.
	 * @details This is a normal virtual function that returns an integer representing 
	 * the current direction of the entity.
	 * @return current direction.
	 */
	virtual const int getCurrentDir() const;
	
	/**
	 * @brief Get the time passed.
	 * @details This is a normal virtual function that returns the time that has passed.
	 * @return Time elapsed.
	 */
	virtual const float getTimePassed();
	
	/**
	 * @brief Set the current direction.
	 * @details Normal virtual function that sets the current direction of the entity.
	 * @param dir is an integer between 1 and 4 that represents the direction.
	 */
	virtual void setCurrentDir(int dir);
	
	/**
	 * @brief Reset the time.
	 * @details This is a normal virtual function that puts the time counter back to zero.
	 */
	virtual void resetTime();
	
	/**
	 * @brief Get the velocity.
	 * @details This function returns the velocity of the game's entity.
	 * @return The velocity.
	 */
	virtual const float getVelocity() const;
	
	/**
	 * @brief Get the target's direction.
	 * @details This function returns the direction of the targeted entity.
	 * @return The target's direction.
	 */
	virtual const Direction getTargetDirection();

protected:
	vector2d _position;
	objectProperties _objectProperties;
	bool _isActive;
	float _rotation;

};

#endif