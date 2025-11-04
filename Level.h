#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "MapAI.h"
#include "Tilemap.h"

class Level
{
private:
	TileMap map;
	std::vector<Tile*> tiles;
	std::unique_ptr<MapAI> mapAI;

	sf::Vector2u levelSize;
	sf::Vector2u tileSize;

public:
	Level(GameWorld& gameWorld);

	sf::Vector2u GetTileSize() const { return tileSize; }
	sf::Vector2u GetLevelSize() const { return levelSize; }
	Tile* GetTile(int x, int y) const;

	void GoToTile(sf::Vector2i startTile, sf::Vector2i goalTile) const;
	void ClearPath() const;
};
