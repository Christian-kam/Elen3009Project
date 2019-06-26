/**
 * @brief DataTypes.
 * @details This is a helper header file that contains the data types used in other classes.
 */
 
#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>
#include <vector>
#include <memory>

const unsigned _windowWidth = 800;
const unsigned _windowHeight = 600;

/**
 * @class vector2d
 * @author Catherine Honegger and Christian Kamwangala 
 * @date 03/10/2015
 * @file DataTypes.h
 * @brief This class defines a general purpose 2D vector.
 */
class vector2d
{
public:
	float x;
	float y;
	
	// Overload for equality
	bool operator == (const vector2d& rhs) 
	{
		return(x == rhs.x && y == rhs.y);
	}
	
	// Overload for less than
	bool operator < (const vector2d& rhs)
	{
		return(x < rhs.x);
	}
	
	// Overload for substraction
	vector2d operator -(const vector2d& rhs)
	{
		if(x - rhs.x < 0)
			return{((x - rhs.x)*-1), rhs.y};
		else
			return{(x - rhs.x), rhs.y};
	}
};


enum class ID
{
	playerShip,
	playerLaser,
	lander,
	landerMissile,
	playerSmartBomb,
	playerMissile,
	powerUp,
	background,
	splashScreen,
	highlight
	
};

/**
 * @class objectProperties
 * @author Catherine Honegger and Christian Kamwangala 
 * @date 03/10/2015
 * @file DataTypes.h
 * @brief This class contains the size of an object and its size.
 */
class objectProperties
{
public:
	ID identifier;
	vector2d ObjectSize;
};

enum class Direction{
	up = 1,
	down,
	left,
	right,
	diagonalUpLeft,
	diagonalUpRight,
	diagonalDownLeft,
	diagonalDownRight,
	randomA
}; 

#endif //DATATYPES_H