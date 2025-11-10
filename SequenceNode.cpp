#include "SequenceNode.h"

SequenceNode::SequenceNode(const std::string& name) : NodeBT(name), m_currentIndex(0)
{
}

SequenceNode::SequenceNode(const std::string& name, std::vector<std::shared_ptr<NodeBT>> children):
	NodeBT(name), m_children(children), m_currentIndex(0)
{
}

NodeState SequenceNode::Tick(float dt, BlackBoard& bb)
{
    if (m_currentIndex >= m_children.size())
    {
        //Reset();
        m_currentIndex = 0;
        return NodeState::Success;
    }

    auto& child = m_children[m_currentIndex];
    NodeState result = child->Tick(dt, bb);

    if (result == NodeState::Running)
    {
        return NodeState::Running;
    }

    if (result == NodeState::Failure)
    {
        Reset();
        return NodeState::Failure;
    }

    child->Reset();
    m_currentIndex++;

    return NodeState::Running;
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

void SequenceNode::Reset()
{
	NodeBT::Reset();

    for (auto& child : m_children)
    {
        child->Reset();
    }

    m_currentIndex = 0;
}
