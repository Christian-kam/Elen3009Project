
#include "PlayerShip.h"
#include <iostream>
PlayerShip::PlayerShip()
{
	//_pPosition.x =0;
	//_pPosition.y =0;
}

Position PlayerShip::move(pDirection dir)
{
	switch(dir)
	{
		case pDirection::up:
			_pPosition.y -= 0.05;
			std::cout << _pPosition.y << std::endl;
			break;
		case pDirection::down:
			_pPosition.y += 0.05;
			break;
		case pDirection::left:
			_pPosition.x -=0.05;
			break;
		case pDirection::right:
			_pPosition.x +=0.05;
			break;
	}
	return _pPosition;
}

//Player::getPosition()
//{
//	
//}

//Player::shootStandard()
//{
	
//}

//Player::shootSpecial()
//{
	

//}