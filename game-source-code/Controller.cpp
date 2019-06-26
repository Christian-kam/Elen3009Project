//Catherine Honegger and Christian Kamwangala
//
#include "Controller.h"

Controller::Controller( const std::shared_ptr<Entity> entityPtr)
:_entity( entityPtr )
{ 
} // nothing else to do

Controller::~Controller()
{
	_entity.reset();
}

void Controller::moveEntity(Direction dir)
{
	float x {_entity->getPosition().x};
	float y  {_entity->getPosition().y};
	auto size {_entity->getObjectProperties().ObjectSize};
	float speed = {_entity->getSpeed()};
	
	switch(dir)
	{
		case Direction::up:
			if (y >= 155)
				y -= speed;
			_entity->setPosition({x,y});
			break;
		case Direction::down:
			if(y < 570)
				y += speed; 
			_entity->setPosition({x,y});
			break;
		case Direction::left:
			if(x >= size.y/1.5)
				x -= speed;
			_entity->setRotation(0);
			_entity->setPosition({x,y});
			break;
		case Direction::right:
			if(x < ((4.97 *_windowWidth) - (size.y/1.8)))
				x += speed;
			_entity->setRotation(180);
			_entity->setPosition({x,y});
			break;
		case Direction::randomA:
		{
			moveRandomA();
			break;
		}
		default:
		;
	}
	_entityInfo = _entity->getObjectProperties();
}

void Controller::moveEntity()
{
	auto x {_entity->getPosition().x};
	auto y  {_entity->getPosition().y};

	auto dir = _entity->getTargetDirection();
	auto velocity = _entity->getVelocity();
	auto _bulletSpeed = _entity->getSpeed();
	
	if( dir == Direction::diagonalUpRight) // go diagonally up  right 
	{
		x += (_bulletSpeed);
		y += velocity;
	}
	else if(dir == Direction::diagonalUpLeft) // go diagonally up left
	{
		x -= (_bulletSpeed);
		y -= velocity;
	}
	else if(dir == Direction::diagonalDownLeft)// go diagonally down left
	{
		x -= (_bulletSpeed);
		y -= velocity;
	}
	else if(dir == Direction::diagonalDownRight)// go diagonally down right
	{
			x += (_bulletSpeed);
			y += velocity;
	}
	_entity->setPosition({x,y});
}

void Controller::moveRandomA()
{
	
	auto deltaT = _entity->getTimePassed();

	auto current_direction = _entity->getCurrentDir();
	
	// Only change direction if time limit has been exceeded
	if (deltaT > 2)
	{
		current_direction = rand()%4+1;
		_entity->setCurrentDir(current_direction);
		_entity->resetTime();
	}

	switch(current_direction)
	{
		case 1:
			 moveEntity(Direction::up);
			break;
		case 2:
			moveEntity(Direction::down);       
			break;
		case 3:
			moveEntity(Direction::left);
			break;        
		case 4:
			moveEntity(Direction::right);
			break;
	}
	_entityInfo = _entity->getObjectProperties();
}

void Controller::moveEntity(vector2d position)
{
	auto x {_entity->getPosition().x};
	auto y  {_entity->getPosition().y};
	
	if(x < position.x)
		moveEntity(Direction::right);
	else if(x > position.x)
		moveEntity(Direction::left);
	if (y < position.y)
		moveEntity(Direction::down);
	else if(y > position.y)
		moveEntity(Direction::up);
}

std::shared_ptr<Entity> Controller::getEntity() const
{
	return _entity;
}
