#pragma once
#include "CollisionLevel.h"
#include "Level.h"
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
	CollisionLevel* level;

	void initWindow();
	void initPlayer();
	void initLevel();

	void updating();
	void rendering();
	void pollEvents();


public:
	Game();
	~Game();

	void running();
};