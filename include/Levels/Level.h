#pragma once
#include "AI/MapAI.h"
#include "Tilemap/Tilemap.h"

class GameWorld;

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
	MapAI* GetMapAI() const { return mapAI.get(); }
};
