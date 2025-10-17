#include "RenderSystem.h"

RenderSystem::RenderSystem(sf::RenderWindow& window) : window(window)
{
}

RenderSystem::~RenderSystem()
{
	drawables.clear();
}

void RenderSystem::update() const
{
	for (sf::Drawable* drawable : drawables)
	{
		window.draw(*drawable);
	}
}

void RenderSystem::RegisterGameObject(sf::Drawable* drawable)
{
	drawables.push_back(drawable);
}

void RenderSystem::UnregisterGameObject(sf::Drawable* drawable)
{
    drawables.erase(
        std::remove(drawables.begin(), drawables.end(), drawable),
        drawables.end()
    );
}
