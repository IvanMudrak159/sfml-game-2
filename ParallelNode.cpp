#include "ParallelNode.h"

#include <SFML/Graphics/RectangleShape.hpp>

ParallelNode::ParallelNode(const std::string& name, ParallelPolicy policy)
	: NodeBT(name), m_policy(policy)
{
}

ParallelNode::ParallelNode(const std::string& name, std::vector<std::shared_ptr<NodeBT>> children,
                           ParallelPolicy policy)
	: NodeBT(name), m_children(children), m_policy(policy)
{
}

void ParallelNode::AddChild(std::shared_ptr<NodeBT> child)
{
    m_children.push_back(child);
}

NodeState ParallelNode::Tick(float dt, BlackBoard& bb)
{
    bool anySuccess = false;

    for (auto& child : m_children)
    {
        NodeState result = child->Tick(dt, bb);

        if (result == NodeState::Success)
        {
            anySuccess = true;

            if (m_policy == ParallelPolicy::RequireOneSuccess)
            {
                state = NodeState::Success;
                return state;
            }
        }

        if (result == NodeState::Failure && m_policy == ParallelPolicy::RequireAllSuccess)
        {
            state = NodeState::Failure;
            return state;
        }
    }

    if (anySuccess)
    {
	    state = NodeState::Running;
    }
    else
    {
	    state = NodeState::Running;
    }
    return state;
}

void ParallelNode::DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb)
{
    for (auto& child : m_children)
        child->DrawDebug(target, states, bb);
}
