#pragma once
#include "CollisionLevel.h"
#include "GameWorld.h"
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
	Level* level;
	//CollisionLevel* level;
	GameWorld* gameWorld;


	void initWindow();
	void initPlayer();
	void initLevel();
	void initGameWorld();

	void updating();
	void rendering();
	void pollEvents() const;


public:
	Game();
	~Game();

	GameWorld* getGameWorld() const;
	void running();
};