 //Catherine Honegger and Christian Kamwangala
 //
#include "PlayerShip.h"

// Static data members of the class;
ID PlayerShip::_id =ID::playerShip;
vector2d PlayerShip::_playerSize {65,65};
objectProperties PlayerShip::info{_id,_playerSize};

PlayerShip::PlayerShip(vector2d _playerPosition)
:Entity(_playerPosition, info), _lives{4}, _playerSpeed{30}
{ 
} // Nothing else to do

void PlayerShip::whenKilled()
{
	if(_lives>1)
	{
		_lives --;
	}
	else
    {
		_isActive = false;
    }
}

const float PlayerShip::getSpeed() const
{
    return _playerSpeed;
}

const int PlayerShip::getLives() const
{
    return _lives;
}