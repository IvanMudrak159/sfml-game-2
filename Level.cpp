#include "Level.h"

#include <iostream>

#include "Tilemap.h"

Level::Level()
{
    constexpr std::array level = {
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    map = new TileMap();
    // create the tilemap from the level definition
    if (!map->load("Sprites/tilemap.png", { 32, 32 }, level.data(), 16, 8))
    {
	    std::cerr << "ERROR WHILE LOADING LEVEL" << std::endl;
        return;
    }
}

Level::~Level()
{
}

void Level::render(sf::RenderWindow& window)
{
    window.draw(*map);
}
