#pragma once
#include "Component.h"
#include "Drawable.h"


class GameObject;
class AgentAI;

class DebugAIAgentRenderer : public Component, public Drawable
{
public:
	DebugAIAgentRenderer(GameObject* owner, AgentAI* agentAI, sf::Vector2u levelSize, sf::Vector2u tileSize);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	AgentAI* m_agentAI;
	sf::Vector2u m_tileSize;
	sf::Vector2u m_levelSize;
};
