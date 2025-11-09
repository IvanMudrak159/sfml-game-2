#include "ConditionNode.h"

ConditionNode::ConditionNode(const std::function<bool(BlackBoard&)>& condition,
    const std::shared_ptr<NodeBT>& child, const std::function<void(sf::RenderTarget&, sf::RenderStates, BlackBoard&)>& debugFunc)
	: m_condition(condition), m_debugFunc(debugFunc), m_child(child)
{
}

NodeState ConditionNode::Tick(float dt, BlackBoard& bb)
{
    if (!m_condition(bb))
        return NodeState::Failure;

    if (m_child == nullptr) return NodeState::Running;

    return m_child->Tick(dt, bb);
}

void ConditionNode::DrawDebug(sf::RenderTarget& target,
    sf::RenderStates states,
    BlackBoard& bb)
{
    if (m_debugFunc)
    {
        m_debugFunc(target, states, bb);
    }

    //m_child->DrawDebug(target, states, bb);
}