#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tile;

class TileMap : public sf::Transformable
{
public:
    bool load(const std::filesystem::path& tileset, sf::Vector2u tileSize,
        const std::vector<Tile*>& tiles, unsigned int width, unsigned int height);

private:
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
};
