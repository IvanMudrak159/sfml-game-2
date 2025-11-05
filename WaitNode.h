#pragma once
#include "ActionNode.h"

class WaitNode : public ActionNode
{
public:
    explicit WaitNode(float waitTime);

protected:
    void OnStart() override;
    NodeState OnTick(float dt) override;
    void OnEnd() override {}

private:
    float m_waitTime;
    float m_elapsed;
};
