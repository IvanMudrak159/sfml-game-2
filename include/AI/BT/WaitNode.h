#pragma once
#include "ActionNode.h"

class WaitNode : public ActionNode
{
public:
    explicit WaitNode(const std::string& name, float waitTime);

protected:
    void OnStart() override;
    NodeState OnTick(float dt, BlackBoard& bb) override;
    void OnEnd() override {}
	void Reset() override { m_elapsed = 0.f; }

public:
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;

private:
    float m_waitTime;
    float m_elapsed;
};
