#include "Tilemap.h"

#include "Tile.h"

class Tile;

bool TileMap::load(const std::filesystem::path& tileset, sf::Vector2u tileSize, const std::vector<Tile*>& tiles,
	unsigned int width, unsigned int height)
{
    if (!m_tileset.loadFromFile(tileset))
    {
		return false;
    }

    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(width * height * 6);


    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            Tile& tile = *tiles[i + j * width];
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];
            tile.setTileset(&m_tileset);
            tile.buildVertices(triangles);
        }
    }
    return true;
}
