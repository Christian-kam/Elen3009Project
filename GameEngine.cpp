#include "GameEngine.h"

GameEngine::GameEngine():_gameView(new GameView())
{}

GameEngine::~GameEngine()
{
	_gameView.reset();
}
void GameEngine::start()
{
	while(!_gameView->terminate())
	{
		_gameView->run();
		
		if(_gameView->getState())
		{
			_gameView.reset(new GameView());
		}
	}
}