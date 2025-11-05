#pragma once
#include "ActionNode.h"

class WaitNode : public ActionNode
{
public:
    explicit WaitNode(float waitTime);

protected:
    void OnStart() override;
    NodeState OnTick(float dt, BlackBoard& bb) override;
    void OnEnd() override {}

public:
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;

private:
    float m_waitTime;
    float m_elapsed;
};
