#include "SequenceNode.h"

SequenceNode::SequenceNode() :m_currentIndex(0)
{
}

SequenceNode::SequenceNode(std::vector<std::shared_ptr<NodeBT>> children): m_children(children), m_currentIndex(0)
{
}

NodeState SequenceNode::Tick(float dt)
{
    while (m_currentIndex < m_children.size())
    {
        NodeState result = m_children[m_currentIndex]->Tick(dt);

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
