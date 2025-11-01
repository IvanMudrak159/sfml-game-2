#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tilemap.h"

class Level
{
private:
	TileMap map;
	std::vector<Tile*> tiles;

	sf::Vector2u levelSize;
	sf::Vector2u tileSize;

public:
	Level(GameWorld& gameWorld);

	sf::Vector2u GetTileSize() const { return tileSize; }
	sf::Vector2u GetLevelSize() const { return levelSize; }
	Tile& getTile(int x, int y) { return *tiles[x + y * levelSize.x]; }
};
