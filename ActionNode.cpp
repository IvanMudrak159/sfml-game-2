#include "ActionNode.h"

ActionNode::ActionNode()
    : started(false)
{
}

NodeState ActionNode::Tick(float dt)
{
    if (!started)
    {
        OnStart();
        started = true;
    }

    NodeState result = OnTick(dt);

    if (result != NodeState::Running)
    {
        OnEnd();
        started = false;
    }

    return result;
}
