#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Tilemap.h"



class Level
{
private:
	TileMap map;
	std::vector<Tile*> tiles;

public:
	Level(GameWorld& gameWorld);
	~Level();
};
