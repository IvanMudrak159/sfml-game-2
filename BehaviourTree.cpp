#include "BehaviourTree.h"
#include <SFML/Graphics/RenderStates.hpp>
#include "NodeBT.h"

BehaviourTree::BehaviourTree(GameObject* owner, std::shared_ptr<NodeBT> root): Component(owner), Drawable(1001),
                                                                               m_root(root)
{
	m_blackboard.Set("tree", this);
	m_blackboard.Set("owner", owner);
}

void BehaviourTree::Update(float dt)
{
	Component::Update(dt);
	m_root->Tick(dt, m_blackboard);
}

BlackBoard& BehaviourTree::GetBlackBoard()
{
	return m_blackboard;
}

void BehaviourTree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_root)
	{
		m_root->DrawDebug(target, states, const_cast<BlackBoard&>(m_blackboard));
	}
}
