#include "WaitNode.h"

WaitNode::WaitNode(float waitTime)
    : m_waitTime(waitTime), m_elapsed(0.f)
{
}

void WaitNode::OnStart()
{
    m_elapsed = 0.f;
}

NodeState WaitNode::OnTick(float dt)
{
    m_elapsed += dt;
    if (m_elapsed >= m_waitTime)
        return NodeState::Success;

    return NodeState::Running;
}
