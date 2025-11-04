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
    sf::Vector2u getTileSize() const { return tileSize; }
    sf::Vector2u getSize() const { return size; }

    void generateFromTiles(const std::vector<Tile*>& tiles);
    NodeAI* getNode(sf::Vector2i coords) const;
};
