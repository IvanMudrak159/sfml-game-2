#pragma once
#include <memory>
#include <vector>

#include "NodeBT.h"


class SequenceNode : public NodeBT
{
public:
    SequenceNode();
    SequenceNode(std::vector<std::shared_ptr<NodeBT>> children);

    NodeState Tick(float dt) override;
    void AddChild(std::shared_ptr<NodeBT> child);

private:
    std::vector<std::shared_ptr<NodeBT>> m_children;
    size_t m_currentIndex;
};
