#pragma once


enum class NodeState
{
    Success,
    Failure,
    Running
};

class NodeBT
{
public:
    virtual ~NodeBT() = default;
    virtual NodeState Tick(float dt) = 0;

protected:
    NodeState state = NodeState::Running;
};
