/**
 * @class Controller
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file Controller.h
 * @brief This class captures the abstraction of a controller object.
 * It is responsible for moving entities in the game.
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Entity.h"
#include "DataTypes.h"
#include "StopWatch.h"


class Controller 
{
public:

	/**
	 * @brief Default Constructor.
	 * @param entityPtr is a shared pointer of type Entity.
	 */
	Controller(const std::shared_ptr<Entity> entityPtr);

	/**
	 * @brief Destructor.
	 * @details Responsible for managing the life of a Controller type object.
	 */
	~Controller();
	
	/**
	 * @brief Move the entity.
	 * @details This function moves an entity in the specified direction.
	 * @param dir specifies the direction in which the enity should move.
	 */
	void moveEntity(Direction dir); 
	
	/**
	 * @brief Move the entity.
	 * @details This is an overload of the original moveEntity function
	 * and is used for the player's heat-seeking missiles.
	 * @param position contains the x and y coordinates.
	 */
	void moveEntity(vector2d position);
	
	/**
	 * @brief Move the enity.
	 * @details This function is another overload of the moveEntity function.
	 * It takes no parameters.
	 */
	void moveEntity();
	
	/**
	 * @brief Get the entity.
	 * @details This function returns a pointer to the Entity being controlled.
	 * @return shared pointer to the entity.
	 */
	std::shared_ptr<Entity> getEntity() const;
	
	
private:
	std::shared_ptr<Entity> _entity;
	objectProperties _entityInfo;
	void moveRandomA();

};

#endif
