#include "ActionNode.h"

ActionNode::ActionNode()
	: started(false)
{
}

NodeState ActionNode::Tick(float dt, BlackBoard& bb)
{
    if (!started)
    {
        OnStart();
        started = true;
    }

    NodeState result = OnTick(dt, bb);

    if (result != NodeState::Running)
    {
        OnEnd();
        started = false;
    }

    return result;
}
