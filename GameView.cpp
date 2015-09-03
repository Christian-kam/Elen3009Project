
#include "GameView.h"

GameView::GameView():_name{"Defender"}, _screen{videoMode(windowWidth, windowHeight), _name}
{
	_screen.setFramerateLimit(120);
	_screen.setKeyRepeatEnabled(false);

}

void GameView::run()
{
	while(_screen.isOpen())
	{
		sf::Event event;
		switch (event.type)
		{
			if(event.key.code == sf::Event::Closed)
				_screen.close();
				break;
		}
	}
}

void GameView::Render()
{
	//_screen.draw();
	_screen.display();
	_screen.clear();

}