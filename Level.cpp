#include "Level.h"

#include <iostream>

#include "Tilemap.h"

Level::Level(GameWorld& gameWorld)
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

    for (unsigned int j = 0; j < 8; ++j)
    {
        for (unsigned int i = 0; i < 16; ++i)
        {
            int number = level[i + j * 16];
            tiles.push_back(std::make_unique<Tile>(
                "Tile_" + std::to_string(i + j * 16),
                gameWorld, number,
                sf::Vector2u{ 32, 32 },
                sf::Vector2f(i * 32.f, j * 32.f)
            ));
        }
    }

    map = TileMap();

    if (!map.load("Sprites/tilemap.png", { 32, 32 }, tiles, 16, 8))
    {
	    std::cerr << "ERROR WHILE LOADING LEVEL" << std::endl;
        return;
    }
}

Level::~Level()
{
}
