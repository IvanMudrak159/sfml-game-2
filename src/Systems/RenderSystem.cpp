#include "Systems/RenderSystem.h"
#include <algorithm>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Core/Drawable.h"

RenderSystem::RenderSystem(sf::RenderWindow& window) : window(window)
{
}

RenderSystem::~RenderSystem()
{
	drawables.clear();
}

void RenderSystem::update()
{
    std::vector<Drawable*> sortedDrawables = drawables;

    std::sort(sortedDrawables.begin(), sortedDrawables.end(),
        [](const Drawable* a, const Drawable* b) {
            return a->GetLayer() < b->GetLayer();
        });

    for (Drawable* drawable : sortedDrawables)
    {
        window.draw(*drawable);
    }

}

void RenderSystem::RegisterGameObject(Drawable* drawable)
{
	drawables.push_back(drawable);
}

void RenderSystem::UnregisterGameObject(Drawable* drawable)
{
    drawables.erase(
        std::remove(drawables.begin(), drawables.end(), drawable),
        drawables.end()
    );
}
