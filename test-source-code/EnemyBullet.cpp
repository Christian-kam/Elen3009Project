#include "EnemyBullet.h"

// Static data members of the class;
ID EnemyBullet::_id =ID::landerMissile;
vector2d EnemyBullet::_bulletSize {3,3};
objectProperties EnemyBullet::info{_id,_bulletSize};

EnemyBullet::EnemyBullet(vector2d startPos, const vector2d& targetPos)
:Entity(startPos, info),_bulletSpeed {3},_targetPos{targetPos}, _startPos{startPos}
{ 
} // Nothing else to do


const float EnemyBullet::getSpeed() const
{
	return _bulletSpeed;
}

const Direction EnemyBullet::getTargetDirection()
{
	float deltaY = _targetPos.y - _startPos.y;
	float deltaX = _targetPos.x - _startPos.x;
	
	Direction target;
	
	_velocity = (deltaY / deltaX) * _bulletSpeed;
	
	if(deltaY < 0 &&  deltaX > 0) // go diagonally up  right 
	{
		target = Direction::diagonalUpRight;
	}
	else if(deltaY < 0 &&  deltaX < 0) // go diagonally up left
	{
		target = Direction::diagonalUpLeft;
	}
	else if(deltaY > 0 &&  deltaX < 0)// go diagonally down left
	{
		target = Direction::diagonalDownLeft;
	}
	else if(deltaY > 0 &&  deltaX > 0)// go diagonally down right
	{
		target = Direction::diagonalDownRight;
	}
	return target;
}

const float EnemyBullet::getVelocity() const
{
	return _velocity;
}
