#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Tilemap.h"



class Level
{
private:
	TileMap map;
	std::vector<std::unique_ptr<Tile>> tiles;

public:
	Level(GameWorld* gameWorld);
	~Level();
};
