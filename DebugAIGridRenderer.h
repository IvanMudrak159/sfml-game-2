#pragma once
#include "Component.h"
#include "MapAI.h"

class DebugAIGridRenderer : public Component, public Drawable
{
public:
    DebugAIGridRenderer(GameObject* owner, MapAI* map)
        : Component(owner), Drawable(10000000), mapAI(map)
    {
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (!mapAI) return;

        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(
            mapAI->GetTileSize().x - 2,
            mapAI->GetTileSize().y - 2
        ));

        sf::Vector2u size = mapAI->GetLevelSize();
        sf::Vector2u tileSize = mapAI->GetTileSize();

        for (unsigned int y = 0; y < size.y; ++y)
        {
            for (unsigned int x = 0; x < size.x; ++x)
            {
                NodeAI* node = mapAI->GetNode(sf::Vector2i(x,y));

                if (!node) continue;

                sf::Vector2f half(tileSize.x * 0.5f, tileSize.y * 0.5f);
                rect.setPosition(node->getPosition() - half);

                if (node->isInPath)
                    rect.setFillColor(sf::Color(0, 0, 200, 100));
                else if (node->isWalkable())
                    rect.setFillColor(sf::Color(0, 200, 0, 100));
                else 
                    rect.setFillColor(sf::Color(200, 0, 0, 100));

                target.draw(rect);
            }
        }
    }

private:
    MapAI* mapAI;
};
