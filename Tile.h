#pragma once
#include "GameObject.h"


class Tile: public GameObject
{
public:
	Tile(GameWorld&, int number = 0, sf::Vector2u size = { 32, 32 }, sf::Vector2f pos = { 0,0 });
	~Tile();

	int getNumber() const;
	void setNumber(int number);
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f pos);
	void buildVertices(sf::Vertex* vertices) const;
	void setTileset(const sf::Texture* tileset);


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	int m_number;
	sf::Vector2u m_tileSize;
	sf::Vector2f m_position;
	const sf::Texture* m_tileset;
};