#pragma once
#include <vector>
#include <memory>

#include "NodeBT.h"

class ConditionNode;

class SelectorNode : public NodeBT
{
public:
    SelectorNode(const std::string& name);
    void AddChild(std::shared_ptr<ConditionNode> child);
    NodeState Tick(float dt, BlackBoard& bb) override;
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;

private:
    std::vector<std::shared_ptr<ConditionNode>> m_children;
    std::shared_ptr<ConditionNode> m_activeChild = nullptr;
};
