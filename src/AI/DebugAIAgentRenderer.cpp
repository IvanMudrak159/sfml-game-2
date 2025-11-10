#include "Components/DebugAIAgentRenderer.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "AI/AgentAI.h"

DebugAIAgentRenderer::DebugAIAgentRenderer(GameObject* owner, AgentAI* agentAI, sf::Vector2u levelSize, sf::Vector2u tileSize): Component(owner), Drawable(1000)
{
	m_agentAI = agentAI;
	m_levelSize = levelSize;
	m_tileSize = tileSize;
}

void DebugAIAgentRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!m_agentAI) return;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(
        m_tileSize.x - 2,
        m_tileSize.y - 2
    ));

    if (!m_agentAI->HasPath()) return;


    std::vector<sf::Vector2f> path = m_agentAI->GetPathPositions();


    for (sf::Vector2f pathTile : path)
    {
        sf::Vector2f half(m_tileSize.x * 0.5f, m_tileSize.y * 0.5f);
        rect.setPosition(pathTile - half);
        rect.setFillColor(sf::Color(0, 0, 200, 100));
        target.draw(rect);
    }
}
