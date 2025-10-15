#pragma once
#include "Player.h"
#include "Times.h"


class Game
{
private:
	unsigned int width;
	unsigned int height;

	std::string title;
	sf::VideoMode vm;
	sf::RenderWindow* window;

	Player* player;

	Times times;

	void initWindow();
	void initPlayer();
	void updating();
	void rendering();
	void pollEvents();


public:
	Game();
	~Game();

	void running();
};