#include "Tile.h"

#include <SFML/Graphics/Texture.hpp>

#include "GameWorld.h"


Tile::Tile(GameWorld* gameWorld, int number, sf::Vector2u size, sf::Vector2f pos) : GameObject(gameWorld), m_number(number), m_tileSize(size), m_position(pos)
{
    gameWorld->getRenderSystem().RegisterGameObject(this);
}

Tile::~Tile()
{
    gameWorld->getRenderSystem().UnregisterGameObject(this);
}

int Tile::getNumber() const
{
	return m_number;
}

void Tile::setNumber(int number)
{
	m_number = number;
}

sf::Vector2f Tile::getPosition() const
{
	return m_position;
}

void Tile::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Tile::buildVertices(sf::Vertex* vertices) const
{
    if (!m_tileset) return;

    int tu = m_number % (m_tileset->getSize().x / m_tileSize.x);
    int tv = m_number / (m_tileset->getSize().x / m_tileSize.x);

    vertices[0].position = m_position;
    vertices[1].position = m_position + sf::Vector2f((float)m_tileSize.x, 0.f);
    vertices[2].position = m_position + sf::Vector2f(0.f, (float)m_tileSize.y);
    vertices[3].position = m_position + sf::Vector2f(0.f, (float)m_tileSize.y);
    vertices[4].position = m_position + sf::Vector2f((float)m_tileSize.x, 0.f);
    vertices[5].position = m_position + sf::Vector2f((float)m_tileSize.x, (float)m_tileSize.y);

    vertices[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
    vertices[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
    vertices[2].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
    vertices[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
    vertices[4].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
    vertices[5].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
}

void Tile::setTileset(const sf::Texture* tileset)
{
    m_tileset = tileset;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!m_tileset) return; // No texture loaded yet

    // Create vertex array for this tile
    sf::Vertex vertices[6];
    buildVertices(vertices);

    // Apply the tileset texture
    states.texture = m_tileset;

    // Draw the tile
    target.draw(vertices, 6, sf::PrimitiveType::Triangles, states);
}
