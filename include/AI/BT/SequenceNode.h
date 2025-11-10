#pragma once
#include <memory>
#include <vector>

#include "NodeBT.h"


class SequenceNode : public NodeBT
{
public:
    SequenceNode(const std::string& name);
    SequenceNode(const std::string& name, std::vector<std::shared_ptr<NodeBT>> children);

    NodeState Tick(float dt, BlackBoard& bb) override;
    void AddChild(std::shared_ptr<NodeBT> child);
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;
    void Reset() override;

private:
    std::vector<std::shared_ptr<NodeBT>> m_children;
    size_t m_currentIndex;
};
