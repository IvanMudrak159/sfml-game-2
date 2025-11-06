#pragma once
#include <iostream>

#include "NodeBT.h"
#include <SFML/Graphics.hpp>

#include "GameObject.h"

template <typename T>
class SearchInRadiusNode : public NodeBT
{
public:
    SearchInRadiusNode(float radius);

    NodeState Tick(float dt, BlackBoard& bb) override;
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;

private:
    float m_radius;
    std::vector<GameObject*> m_lastFound;
};

template <typename T>
SearchInRadiusNode<T>::SearchInRadiusNode(float radius)
{
	m_radius = radius;
}

template <typename T>
NodeState SearchInRadiusNode<T>::Tick(float dt, BlackBoard& bb)
{
    static_assert(std::is_base_of<GameObject, T>::value,
        "SearchInRadiusNode<T>: T must derive from GameObject");

    if (!bb.Has("owner"))
        return NodeState::Failure;

    GameObject* owner = bb.Get<GameObject*>("owner");
    GameWorld* world = owner->getGameWorld();

    auto objects = world->GetObjectsInRadius(owner->getPosition(), m_radius);
    m_lastFound.clear();

    for (auto* obj : objects)
    {
        if (dynamic_cast<T*>(obj))
            m_lastFound.push_back(obj);
    }

    bb.Set("targets", m_lastFound);

    if (m_lastFound.empty())
    {
        return NodeState::Running;
    }
    std::cout << "We've found the player: " << typeid(T).name() << std::endl;
    return NodeState::Success;
}

template <typename T>
void SearchInRadiusNode<T>::DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb)
{
	NodeBT::DrawDebug(target, states, bb);

    if (!bb.Has("owner"))
        return;

    GameObject* owner = bb.Get<GameObject*>("owner");
    if (!owner)
        return;

    sf::Vector2f pos = owner->getPosition();

    sf::CircleShape shape(m_radius);
    shape.setOrigin(sf::Vector2f(m_radius, m_radius));
    shape.setPosition(pos);

    shape.setFillColor(sf::Color(255, 0, 0, 50));

    target.draw(shape, states);
}
