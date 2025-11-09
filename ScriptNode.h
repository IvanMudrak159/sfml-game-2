#pragma once
#include "NodeBT.h"
#include <functional>

class ScriptNode : public NodeBT
{
public:
    using TickFunc = std::function<NodeState(float, BlackBoard&)>;
    using DebugFunc = std::function<void(sf::RenderTarget&, sf::RenderStates, BlackBoard&)>;

    ScriptNode(TickFunc tickFunc, DebugFunc debugFunc = nullptr)
        : m_tickFunc(tickFunc), m_debugFunc(debugFunc)
    {
    }

    NodeState Tick(float dt, BlackBoard& bb) override
    {
        if (m_tickFunc)
            return m_tickFunc(dt, bb);

        return NodeState::Failure;
    }

    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override
    {
        if (m_debugFunc)
            m_debugFunc(target, states, bb);
    }

private:
    TickFunc m_tickFunc;
    DebugFunc m_debugFunc;
};
