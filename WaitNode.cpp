#include "WaitNode.h"

#include <iostream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

#include "BlackBoard.h"
#include "GameObject.h"

WaitNode::WaitNode(float waitTime)
	: m_waitTime(waitTime), m_elapsed(0.f)
{
}

void WaitNode::OnStart()
{
    m_elapsed = 0.f;
}

NodeState WaitNode::OnTick(float dt, BlackBoard& bb)
{
    m_elapsed += dt;
    if (m_elapsed >= m_waitTime)
        return NodeState::Success;

    return NodeState::Running;
}

void WaitNode::DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb)
{
	ActionNode::DrawDebug(target, states, bb);

	GameObject* owner = bb.Get<GameObject*>("owner");

    if (owner == nullptr) return;

    sf::Vector2f size(40, 10.f);
    sf::Vector2f centerPos = owner->getPosition() - size * 0.5f;


	sf::RectangleShape bg(size);
    bg.setFillColor(sf::Color(0, 0, 0, 150));
    bg.setPosition(centerPos);
    target.draw(bg, states);

    sf::Font font;
    if (!font.openFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font\n";
    }

    sf::Text text(font);
    text.setCharacterSize(9);
    text.setFillColor(sf::Color::White);

    float remaining = std::max(0.f, m_waitTime - m_elapsed);
    text.setString("Wait: " + std::to_string(remaining).substr(0, 4));

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(textBounds.position.x + textBounds.size.x / 2.f, textBounds.position.y + textBounds.size.y / 2.f));
    text.setPosition(owner->getPosition());
    target.draw(text, states);
}

