#include "SelectorNode.h"

void SelectorNode::AddChild(std::shared_ptr<ConditionNode> child)
{
    m_children.push_back(child);
}

NodeState SelectorNode::Tick(float dt, BlackBoard& bb)
{
	m_activeChild = nullptr;
    for (auto& child : m_children)
    {
        NodeState result = child->Tick(dt, bb);

        if (result == NodeState::Success || result == NodeState::Running)
        {
            m_activeChild = child;
            return result;
        }
    }

    return NodeState::Failure;
}

void SelectorNode::DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb)
{
	NodeBT::DrawDebug(target, states, bb);

    for (auto& child : m_children)
    {
        child->DrawDebug(target, states, bb);
    }

    if (m_activeChild)
    {
		m_activeChild->GetChild().DrawDebug(target, states, bb);
    }
}
