/**
 * @class GameEngine
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file GameEngine.h
 * @brief This class manages the execution of the game.
 */

#include "GameView.h"
#include "DataTypes.h"

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine
{
public:
	/**
	 * @brief Default constructor.
	 * @details Creates an instance of GameEngine and initialises all data members.
	 */
	GameEngine();
	
	/**
	 * @brief GameEngine Destructor.
	 * @details Releases all resources used by GameEngine.
	 */
	~GameEngine();
	
	/**
	 * @brief GameEngine Start.
	 * @details This function starts the game in main().
	 */
	void start();
private:
	std::unique_ptr<GameView> _gameView;
};

#endif