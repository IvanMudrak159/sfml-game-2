#include "Level.h"

#include <iostream>

#include "AgentAI.h"
#include "Debug.h"
#include "DebugAIGridRenderer.h"
#include "Enemy.h"
#include "TileFactory.h"
#include "Tilemap.h"

Level::Level(GameWorld& gameWorld)
{
	levelSize = sf::Vector2u(16, 8);
	tileSize = sf::Vector2u(32, 32);

	constexpr std::array level = {
		0, 0, 0, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 2, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 2, 3, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 3, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};


	for (unsigned int j = 0; j < levelSize.y; ++j)
	{
		for (unsigned int i = 0; i < levelSize.x; ++i)
		{
			int index = i + j * levelSize.x;
			int tileType = level[index];
			Tile* tile = TileFactory::createTile(tileType, index, gameWorld, sf::Vector2u{tileSize.x, tileSize.y},
			                                     sf::Vector2f(i * tileSize.x, j * tileSize.y));

			tiles.push_back(tile);
		}
	}

	map = TileMap();

	if (!map.load("Sprites/tilemap.png", tileSize, tiles, levelSize.x, levelSize.y))
	{
		std::cerr << "ERROR WHILE LOADING LEVEL" << std::endl;
		return;
	}

	mapAI = std::make_unique<MapAI>(levelSize, tileSize);
	mapAI->GenerateFromTiles(tiles);

	if (Debug::isEnabled()) 
	{
		GameObject* debugGO = gameWorld.createGameObject("AIDebug");
		debugGO->addComponent<DebugAIGridRenderer>(mapAI.get());
	}


	gameWorld.createObject<Enemy>("Enemy", gameWorld, this);
}

Tile* Level::GetTile(int x, int y) const
{
	if (x < 0 || y < 0 || x >= levelSize.x || y >= levelSize.y)
	{
		return nullptr;
	}
	return tiles[x + y * levelSize.x];
}