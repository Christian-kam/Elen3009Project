
#include <SFML/Graphics.hpp>
#include <string>

#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#define windowWidth 800
#define windowHeight 600

using renderWindow = sf::RenderWindow;
using title = std::string;
using videoMode = sf::VideoMode;


class GameView{
	
public:
	GameView();
	void run();
private:
	title _name;
	renderWindow _screen;
	void Render();
};

#endif