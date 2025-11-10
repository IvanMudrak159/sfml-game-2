#include "Tilemap/TileFactory.h"

#include <string>

#include "Components/BoxCollider.h"
#include "Core/GameWorld.h"
#include "Tilemap/Tile.h"
#include "Tilemap/TileData.h"


Tile* TileFactory::createTile(int type, int index, GameWorld& gameWorld, sf::Vector2u size = { 32, 32 }, sf::Vector2f pos = { 0,0 })
{
    const TileData& data = tileSet[type];

    Tile* tile = gameWorld.createObject<Tile>(
        "Tile_" + std::to_string(index),
        gameWorld,
        type,
        size,
        pos);


    if (data.hasCollider) {
        tile->addComponent<BoxCollider>(pos + sf::Vector2f(size.x * 0.5f, size.y * 0.5f), sf::Vector2f(size));
    }

    return tile;
}
