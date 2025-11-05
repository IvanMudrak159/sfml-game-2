#include "Game.h"
#include "GameWorld.h"


void Game::initWindow()
{
	width = 512;
	height = 256;
	title = "SFML with classes";
	vm = sf::VideoMode({ width, height });
	window = std::make_unique<sf::RenderWindow>(vm, title);
	window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	GameObject* player = gameWorld->createObject<Player>("Player", *gameWorld, level.get());
	player->setPosition(sf::Vector2f(16, 16));
}

void Game::initLevel()
{
	level = std::make_unique<Level>(*gameWorld);
	//level = new CollisionLevel(gameWorld,width * 0.5f, height * 0.5f);
}

void Game::initGameWorld()
{
	gameWorld = std::make_unique<GameWorld>(*window);
}

void Game::updating()
{
	pollEvents();

	times.nextDeltaTime();

	float dt = times.getDeltaTime();

	gameWorld->update(dt);
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
}
