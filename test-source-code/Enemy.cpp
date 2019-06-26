 //Catherine Honegger and Christian Kamwangala
 //
#include "Enemy.h"

// Static data members of the class;
ID Enemy::_id =ID::lander;
vector2d Enemy::_enemySize {23,23};
objectProperties Enemy::info{_id,_enemySize};
Enemy::Enemy(vector2d _enemyPosition)
:Entity(_enemyPosition, info), current_direction{rand()%4+1}, _enemySpeed {2.5}
{ 
    timer.start();
} 

const int Enemy::getCurrentDir() const 
{
	return current_direction;
}

void Enemy::setCurrentDir(int dir)
{
	current_direction = dir;
}

const float Enemy::getTimePassed() 
{
	auto deltaT = timer.stop();
	return deltaT;
}

void Enemy::resetTime()
{
   // std::cout << "Reset" << std::endl;
	timer.reset();
	timer.start();
}

const float Enemy::getSpeed() const
{
    return _enemySpeed;
}
