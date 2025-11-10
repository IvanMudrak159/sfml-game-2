#pragma once
#include "NodeBT.h"

class ActionNode : public NodeBT
{
public:
    ActionNode(const std::string& name);
    NodeState Tick(float dt, BlackBoard& bb) override;

protected:
    virtual void OnStart() {}
    virtual NodeState OnTick(float dt, BlackBoard& bb) = 0;
    virtual void OnEnd() {}

private:
    bool started;
};
