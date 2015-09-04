// 
#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

enum class pDirection{
	up,
	down,
	left,
	right
};

struct Position // should be class
{
	float x;
	float y;
};

class PlayerShip // : Spaceship inheritance
{	
public:
	PlayerShip();
	Position move(pDirection dir);
private:
	Position _pPosition;
};

#endif