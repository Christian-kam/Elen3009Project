
#include "GameView.h"

GameView::GameView()
:_playerTexture()
,_playerID()
,_name{"Defender"}
,_screen{videoMode(_windowWidth, _windowHeight), _name}

{
	_screen.setVerticalSyncEnabled(true);
	//_screen.setFramerateLimit(120);
	_screen.setKeyRepeatEnabled(false);
	
	if(!_playerTexture.loadFromFile("resources/Player.png"))
		std::cout << "Error screen" << std::endl;
	_playerID.setTexture(_playerTexture);
	_playerID.setPosition(100,200);
	_playerID.setOrigin(15,15);

}

void GameView::run()
{
	float frameCounter = 0, frameSpeed = 500;
	Clock clock;
	
	bool updateFrame = true;
	while(_screen.isOpen())
	{
		EventManager eventManager;
		sf::Event event;
		while (_screen.pollEvent(event))
		{
			eventManager.processEvent(event);
		}
		updateScreen(eventManager);
		if(updateFrame)
			frameCounter += frameSpeed*clock.restart().asSeconds();
		else
			frameCounter = 0;
		
		frameCounter += frameSpeed*clock.restart().asSeconds();
		
		renderScreen();
	}
}

void GameView::renderScreen()
{
	_screen.draw(_playerID);
	_screen.display();
	_screen.clear();

}

void GameView::updateScreen(const EventManager& eventManager)
{
	sf::Vector2f movement(0.f, 0.f);
	if(_moveUp)
	{
		movement.y =eventManager.getYPosition();
	}
	if(_moveDown)
	{
		movement.y =eventManager.getYPosition();
	}
	if(_moveLeft)
	{
		_playerID.setTexture(_playerTexture);
		_playerID.setRotation(0);
		movement.x =eventManager.getXPosition();
	}
	if(_moveRight)
	{
		_playerID.setRotation(180);
		movement.x =eventManager.getXPosition();
	}
	_playerID.move(movement);

}