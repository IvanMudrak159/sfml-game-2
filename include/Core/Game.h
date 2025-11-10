#pragma once
#include "Times.h"


class Level;
class GameWorld;

class Game
{
private:
	unsigned int width;
	unsigned int height;

	std::string title;
	sf::VideoMode vm;

	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<GameWorld> gameWorld;
	std::unique_ptr<Level> level;

	Times times;

	//CollisionLevel* level;


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

	void running();
};
