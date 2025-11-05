#include "Plane.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "BoxCollider.h"
#include "GameWorld.h"

Plane::Plane(std::string name, GameWorld& gameWorld) : GameObject(name, gameWorld), Drawable(0)
{
	vertices = sf::VertexArray (sf::PrimitiveType::Triangles, 6);

	// define the position of the vertices's points
	vertices[0].position = sf::Vector2f(100.f, 100.f);
	vertices[1].position = sf::Vector2f(100.f, 0);
	vertices[2].position = sf::Vector2f(0, 0);

	// define the position of the vertices's points
	vertices[3].position = sf::Vector2f(100.f, 100.f);
	vertices[4].position = sf::Vector2f(0, 100.f);
	vertices[5].position = sf::Vector2f(0, 0);


	// define the color of the vertices's points
	vertices[0].color = sf::Color::Red;
	vertices[1].color = sf::Color::Blue;
	vertices[2].color = sf::Color::Green;
	vertices[3].color = sf::Color::Red;
	vertices[4].color = sf::Color::Blue;
	vertices[5].color = sf::Color::Green;

	addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100.0f, 100.0f));

	gameWorld.getRenderSystem().RegisterGameObject(this);

}

Plane::~Plane()
{
	gameWorld.getRenderSystem().UnregisterGameObject(this);
}

void Plane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(vertices, states);
}
