#include "Core/GameObject.h"
#include "Core/GameWorld.h"

GameObject::GameObject(std::string name, GameWorld& gameWorld) : name(name), gameWorld(gameWorld)
{
}

GameObject::~GameObject()
{
    for (auto& c : components)
    {
        if (auto drawable = dynamic_cast<Drawable*>(c.get()))
        {
            gameWorld.getRenderSystem().UnregisterGameObject(drawable);
        }
    }
}

void GameObject::update(float dt) const
{
    for (auto& comp : components) {
        comp->Update(dt);
    }
}

bool GameObject::hasCollider() const
{
    return getComponent<BoxCollider>() != nullptr;
}

GameWorld* GameObject::getGameWorld() const
{
    return &gameWorld;
}
