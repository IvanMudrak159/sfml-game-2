#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "NodeAI.h"
#include "Tile.h"

class MapAI
{
private:
    sf::Vector2u size;
    sf::Vector2u tileSize;
    std::vector<std::vector<NodeAI*>> grid;

public:
    MapAI(sf::Vector2u size, sf::Vector2u tileSize);
    ~MapAI();

    void ClearPath() const;
    sf::Vector2u GetTileSize() const { return tileSize; }
    sf::Vector2u GetLevelSize() const { return size; }

    void GenerateFromTiles(const std::vector<Tile*>& tiles);
    NodeAI* GetNode(sf::Vector2i coords) const;
};
