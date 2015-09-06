#include <iostream>
#include "PlayerShip.h"
using namespace std;
PlayerShip::PlayerShip()
{
	_pPosition.x =100;
	_pPosition.y =200;
	_speed = 0.5;
}

Position PlayerShip::move(pDirection dir)
{
	switch(dir)
	{
		case pDirection::up:
			_pPosition.y --;
			//cout<<_pPosition.x<< _pPosition.y <<endl;
			break;
		case pDirection::down:
			_pPosition.y ++;
			//cout<<_pPosition.x<< _pPosition.y <<endl;
			break;
		case pDirection::left:
			_pPosition.x --;
			//cout<<_pPosition.x<< _pPosition.y <<endl;
			break;
		case pDirection::right:
			_pPosition.x ++;
			//cout<<_pPosition.x<< _pPosition.y <<endl;
			break;
	}
	return _pPosition;
}

float PlayerShip::getSpeed() const
{
	return _speed;
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