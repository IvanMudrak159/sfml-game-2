#include "AI/MapAI.h"

#include "Tilemap/Tile.h"
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <AI/NodeAI.h>

MapAI::MapAI(sf::Vector2u size, sf::Vector2u tileSize) : size(size), tileSize(tileSize)
{
    // grid[height][width]
    grid.resize(size.y, std::vector<NodeAI*>(size.x, nullptr));
}

MapAI::~MapAI()
{
    for (auto& row : grid)
    {
        for (auto node : row)
        {
            delete node;
        }
    }
}

void MapAI::ClearPath() const
{
    for (auto& row : grid)
    {
        for (auto node : row)
        {
            node->setParent(nullptr);
            node->setG(std::numeric_limits<float>::max());
            node->setH(0);
        }
    }
}

void MapAI::GenerateFromTiles(const std::vector<Tile*>& tiles)
{
    float tileHalfSize = tileSize.x * 0.5f;

    for (unsigned int y = 0; y < size.y; ++y)          // height
    {
        for (unsigned int x = 0; x < size.x; ++x)      // width
        {
            int index = x + y * size.x;
            Tile* t = tiles[index];

            bool walkable = !t->hasCollider();

            sf::Vector2f pos(
                x * tileSize.x + tileHalfSize,
                y * tileSize.y + tileHalfSize
            );

            grid[y][x] = new NodeAI(pos, walkable);
        }
    }

    // --- ADD NEIGHBORS ---
    for (unsigned int y = 0; y < size.y; ++y)
    {
        for (unsigned int x = 0; x < size.x; ++x)
        {
            NodeAI* node = grid[y][x];
            if (!node->isWalkable()) continue;

            // left
            if (x > 0 && grid[y][x - 1]->isWalkable())
                node->addNeighbor(grid[y][x - 1]);

            // right
            if (x < size.x - 1 && grid[y][x + 1]->isWalkable())
                node->addNeighbor(grid[y][x + 1]);

            // up
            if (y > 0 && grid[y - 1][x]->isWalkable())
                node->addNeighbor(grid[y - 1][x]);

            // down
            if (y < size.y - 1 && grid[y + 1][x]->isWalkable())
                node->addNeighbor(grid[y + 1][x]);
        }
    }
}


NodeAI* MapAI::GetNode(sf::Vector2i coords) const
{
	if (coords.x < 0 || coords.y < 0 || coords.x >= size.x || coords.y >= size.y)
	{
		return nullptr;
	}
	return grid[coords.y][coords.x];
}
