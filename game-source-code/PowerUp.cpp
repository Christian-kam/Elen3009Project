#include "PowerUP.h"

// Static data members of the class;
ID PowerUp::_id =ID::powerUp;
vector2d PowerUp::_powerUpSize {67,49};
objectProperties PowerUp::info{_id,_powerUpSize};

PowerUp::PowerUp(vector2d _PowerUpPosition)
:Entity(_PowerUpPosition, info),_powerUpSpeed{3}
{ 
} // Nothing else to do

const float PowerUp::getSpeed() const
{
    return _powerUpSpeed;
}
