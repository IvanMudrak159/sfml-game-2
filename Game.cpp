#include "Game.h"

#include <iostream>


void Game::initWindow()
{
	width = 512;
	height = 256;
	title = "SFML with classes";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	player = new Player(gameWorld);
}

void Game::initLevel()
{
	level = new Level(gameWorld);
	//level = new CollisionLevel(gameWorld,width * 0.5f, height * 0.5f);
}

void Game::initGameWorld()
{
	gameWorld = new GameWorld(*window);
}

void Game::updating()
{
	pollEvents();

	times.nextDeltaTime();

	float dt = times.getDeltaTime();

	gameWorld->update(dt);
	player->update(dt);
}

void Game::rendering()
{
	window->clear();

	gameWorld->render();

	window->display();

}

void Game::pollEvents() const
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();
			}
		}
	}
}

void Game::running()
{
	while (window->isOpen())
	{
		updating();
		rendering();
	}
}

Game::Game()
{
	initWindow();
	initGameWorld();
	initLevel();
	initPlayer();
}

Game::~Game()
{
	delete window;
	delete player;
	delete level;
	delete gameWorld;
}

GameWorld* Game::getGameWorld() const
{
	return gameWorld;
}

