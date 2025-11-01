#include "TileFactory.h"

#include <string>

#include "Tile.h"
#include "TileData.h"

std::unique_ptr<Tile> TileFactory::createTile(int type, int index, GameWorld& gameWorld, sf::Vector2u size = { 32, 32 }, sf::Vector2f pos = { 0,0 })
{
    const TileData& data = tileSet[type];

    auto tile = std::make_unique<Tile>(
        "Tile_" + std::to_string(index),
        gameWorld,
        type,
        size,
        pos
    );

    if (data.hasCollider) {
        tile->addComponent<BoxCollider>(pos, sf::Vector2f(size));
    }

    return tile;
}