/**
 * @class CollisionDetection
 * @author Catherine Honegger and Christian Kamwangala
 * @date 02/10/2015
 * @file CollisionDetection.h
 * @brief This class is responsible for managing the collisions between entities in the game.
 */
#include "DataTypes.h"
#include "Entity.h"

#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

class CollisionDetection
{
public:
	/**
	 * @brief Default constructor.
	 * @param entity1 is a shared pointer of Entity type.
	 * @param entity2 is another shared pointer of Entity type.
	 */
	CollisionDetection(const std::shared_ptr<Entity> entity1, const std::shared_ptr<Entity> entity2);
	
	/**
	 * @brief Destructor. 
	 * @details Manages the life of a CollisionDetection object
	 */
	~CollisionDetection();
	
	/**
	 * @brief This function returns true if two entities have collided, false otherwise.
	 * @return True or false.
	 */
	bool isColide();
private:
	std::shared_ptr<Entity> _entity1;
	std::shared_ptr<Entity> _entity2;
};

#endif