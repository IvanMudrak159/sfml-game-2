#pragma once
#include "NodeBT.h"
#include <functional>
#include <memory>

class ConditionNode : public NodeBT
{
public:
    ConditionNode(const std::function<bool(BlackBoard&)>& condition,
        const std::shared_ptr<NodeBT>& child, const std::function<void(sf::RenderTarget&, sf::RenderStates, BlackBoard&)>& debugFunc = nullptr);

    NodeState Tick(float dt, BlackBoard& bb) override;
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;
    NodeBT& GetChild() const { return *m_child; }

private:
    const std::function<bool(BlackBoard&)> m_condition;
    const std::function<void(sf::RenderTarget&, sf::RenderStates, BlackBoard&)> m_debugFunc;
    const std::shared_ptr<NodeBT> m_child;
};
