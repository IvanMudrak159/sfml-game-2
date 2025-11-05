#pragma once
#include "NodeBT.h"

class ActionNode : public NodeBT
{
public:
    ActionNode();

    NodeState Tick(float dt) override;

protected:
    virtual void OnStart() {}
    virtual NodeState OnTick(float dt) = 0;
    virtual void OnEnd() {}

private:
    bool started;
};
