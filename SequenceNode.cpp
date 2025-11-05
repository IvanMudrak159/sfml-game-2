#include "SequenceNode.h"

SequenceNode::SequenceNode() :m_currentIndex(0)
{
}

SequenceNode::SequenceNode(std::vector<std::shared_ptr<NodeBT>> children): m_children(children), m_currentIndex(0)
{
}

NodeState SequenceNode::Tick(float dt, BlackBoard& bb)
{
    while (m_currentIndex < m_children.size())
    {
        NodeState result = m_children[m_currentIndex]->Tick(dt, bb);

        if (result == NodeState::Running)
        {
            return NodeState::Running;
        }

        if (result == NodeState::Failure)
        {
            m_currentIndex = 0;
            return NodeState::Failure;
        }

        m_currentIndex++;
    }

    m_currentIndex = 0;
    return NodeState::Success;
}

void SequenceNode::AddChild(std::shared_ptr<NodeBT> child)
{
	m_children.push_back(child);
}

void SequenceNode::DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb)
{
	NodeBT::DrawDebug(target, states, bb);

    if (m_currentIndex >= m_children.size()) return;
    m_children[m_currentIndex]->DrawDebug(target, states, bb);
}
