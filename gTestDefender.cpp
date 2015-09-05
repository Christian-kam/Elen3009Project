// Authors: Christian Kamwangala 685344
//          Catherine Honegger 566247
#include "PlayerShip.h"
#include <gtest/gtest.h>

TEST(PlayerShip, moveUp)
{
	PlayerShip ship;
	Position testP = ship.move(pDirection::up);
	EXPECT_FLOAT_EQ((0-0.05),testP.y);	
}

TEST(PlayerShip, moveDown)
{
	PlayerShip ship;
	Position testP = ship.move(pDirection::down);
	EXPECT_FLOAT_EQ((0+0.05),testP.y);	
}

TEST(PlayerShip, moveLeft)
{
	PlayerShip ship;
	Position testP = ship.move(pDirection::left);
	EXPECT_FLOAT_EQ((0-0.05),testP.x);	
}

TEST(PlayerShip, moveRight)
{
	PlayerShip ship;
	Position testP = ship.move(pDirection::right);
	EXPECT_FLOAT_EQ((0+0.05),testP.x);	
}