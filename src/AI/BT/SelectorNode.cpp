#include "AI/BT/SelectorNode.h"
#include "AI/BT/ConditionNode.h"

SelectorNode::SelectorNode(const std::string& name): NodeBT(name)
{
}

void SelectorNode::AddChild(std::shared_ptr<ConditionNode> child)
{
    m_children.push_back(child);
}

NodeState SelectorNode::Tick(float dt, BlackBoard& bb)
{
    std::shared_ptr<ConditionNode> chosenChild = nullptr;

    for (auto& child : m_children)
    {
        NodeState result = child->TickCondition(bb);

        if (result != NodeState::ConditionFailed)
        {
            chosenChild = child;
            break;
        }
    }

    if (!chosenChild)
    {
        if (m_activeChild)
        {
            m_activeChild->Reset();
        }
        m_activeChild = nullptr;
        return NodeState::Failure;
    }

    if (chosenChild != m_activeChild)
    {
        if (m_activeChild)
        {
            m_activeChild->Reset();
        }
        m_activeChild = chosenChild;
    }

    return m_activeChild->Tick(dt, bb);
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
