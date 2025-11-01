#pragma once
#include <SFML/Graphics/VertexArray.hpp>

#include "GameObject.h"


class Plane : public GameObject
{
private:
	sf::VertexArray vertices;

public:
	Plane(std::string name, GameWorld& gameWorld);
	~Plane();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
