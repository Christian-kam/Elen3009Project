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
	float getSpeed() const;
private:
	Position _pPosition;
	float _speed;
};

#endif