#include "Level.h"

#include <iostream>

#include "TileFactory.h"
#include "Tilemap.h"

Level::Level(GameWorld& gameWorld)
{
    constexpr std::array level = {
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
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
			int index = i + j * 16;
            int tileType = level[index];
            Tile* tile = TileFactory::createTile(tileType, index, gameWorld, sf::Vector2u{ 32, 32 }, sf::Vector2f(i * 32.f, j * 32.f));


        	tiles.push_back(tile);

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
