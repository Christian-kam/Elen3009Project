#include "Entity.h"

Entity::Entity(vector2d& position, objectProperties& objProps):
_position{position}, 
_objectProperties{objProps},
_isActive{true},
_rotation{180}
{} // Nothing else to do

/**
 * @brief Destructor for Entity
 * @details [releases resources used by entity]
 * @return [n/a]
 */
Entity::~Entity()
{ }
const vector2d& Entity::getPosition() const
{
	return _position;
}

const objectProperties& Entity::getObjectProperties() const
{
	return _objectProperties;
}

void Entity::setPosition(vector2d pos)
{
	_position = pos;
}

const float Entity::getRotation() const
{
	return _rotation;
}

void Entity::setRotation(float rotation)
{
	_rotation = rotation;
}

bool Entity::isActive() const
{
	return _isActive;
}

void Entity::whenKilled()
{
	_isActive = false;
}

const int Entity::getCurrentDir() const
{
	return 0;
}
const float Entity::getTimePassed()
{
	return 0;
}
void Entity::setCurrentDir(int dir)
{
}
void Entity::resetTime()
{
}

const float Entity::getVelocity() const
{
	return 0;
}

const Direction Entity::getTargetDirection()
{
	return Direction::up;
}