#include "GameObject.h"
#include "GameWorld.h"

GameObject::GameObject(GameWorld* gameWorld) : gameWorld(gameWorld)
{
    gameWorld->getRenderSystem().RegisterGameObject(this);
}

GameObject::~GameObject()
{
    gameWorld->getRenderSystem().UnregisterGameObject(this);
}

GameWorld* GameObject::getGameWorld() const
{
    return gameWorld;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& c : components)
    {
        if (auto drawable = dynamic_cast<sf::Drawable*>(c.get()))
        {
            target.draw(*drawable, states);
        }
    }
}
