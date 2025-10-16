#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Tilemap.h"



class Level
{
private:
	TileMap* map;

public:
	Level();
	~Level();

	void render(sf::RenderWindow& window);
};
