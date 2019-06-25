//Catherine Honegger and Christian Kamwangala
 //
#include "Bullet.h"

// Static data members of the class;
ID Bullet::_id =ID::playerLaser;
vector2d Bullet::_bulletSize {15,4};
objectProperties Bullet::info{_id,_bulletSize};

Bullet::Bullet(vector2d _bulletPosition)
:Entity(_bulletPosition, info),_bulletSpeed {25}
{ 
} // Nothing else to do

const float Bullet::getSpeed() const
{
    return _bulletSpeed;
}
