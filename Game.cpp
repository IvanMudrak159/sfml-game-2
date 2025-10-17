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
	sf::Texture playerTexture;

	if (!playerTexture.loadFromFile("Sprites/player.png"))
	{
		std::cerr << "Error loading texture: " << "PLAYER TEXTURE" << std::endl;
	}


	player = new Player(playerTexture);


	if (!player)
		std::cerr << "Player is nullptr!" << std::endl;
}

void Game::initLevel()
{
	//level = new Level();
	level = new CollisionLevel(width * 0.5f, height * 0.5f);
}

void Game::updating()
{
	pollEvents();

	times.nextDeltaTime();

	float dt = times.getDeltaTime();


	player->update(dt);
}

void Game::rendering()
{
	window->clear();

	level->render(*window);
	window->draw(*player);
	//render here

	window->display();

}

void Game::pollEvents()
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
	initPlayer();
	initLevel();
}

Game::~Game()
{
	delete window;
	delete player;
	delete level;
}

