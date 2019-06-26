/**
 * @class PowerUp
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file PowerUP.h
 * @brief This class models a power-up object that appears during gameplay
 */
 
#ifndef POWERUP_H
#define POWERUP_H

#include "DataTypes.h"
#include "Entity.h"

class PowerUp : public Entity
{
public:
	
	/**
	 * @brief Default constructor.
	 * @param position contains x and y coordinates of the power-up's position.
	 */
	 PowerUp(vector2d position);
	 
	 /**
	  * @brief Get the speed.
	  * @details This function returns the speed of the power-up.
	  * @return The speed.
	  */
	const float getSpeed() const;

private:
	
	static ID _id;
	static vector2d _powerUpSize;

	float _powerUpSpeed;
	static objectProperties info;

};
#endif
