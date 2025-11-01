#pragma once
#include <memory>
#include <SFML/System/Vector2.hpp>

#include "GameWorld.h"

class Tile;

class TileFactory
{
public:
	static std::unique_ptr<Tile> createTile(int type, int index, GameWorld& gameWorld, sf::Vector2u size, sf::Vector2f pos);
};
