#include "ConditionNode.h"

ConditionNode::ConditionNode(const std::string& name, const std::function<bool(BlackBoard&)>& condition,
    const std::shared_ptr<NodeBT>& child, const std::function<void(sf::RenderTarget&, sf::RenderStates, BlackBoard&)>& debugFunc)
	: NodeBT(name), m_condition(condition), m_debugFunc(debugFunc), m_child(child)
{
}

NodeState ConditionNode::Tick(float dt, BlackBoard& bb)
{
    if (!m_condition(bb))
    {
        return NodeState::ConditionFailed;
    }

    return m_child->Tick(dt, bb);
}

NodeState ConditionNode::TickCondition(BlackBoard& bb) const
{
	if (!m_condition(bb))
	{
		return NodeState::ConditionFailed;
	}
	return NodeState::Success;
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

void ConditionNode::Reset()
{
	NodeBT::Reset();

	m_child->Reset();
}
