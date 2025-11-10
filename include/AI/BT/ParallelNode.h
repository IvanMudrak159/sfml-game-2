#pragma once
#include <memory>
#include <vector>

#include "NodeBT.h"

enum class ParallelPolicy
{
    RequireAllSuccess,
    RequireOneSuccess,
    RequireAllFailure,
    RequireOneFailure
};

class ParallelNode : public NodeBT
{
public:
    ParallelNode(const std::string& name, ParallelPolicy policy = ParallelPolicy::RequireAllSuccess);
    ParallelNode(const std::string& name, std::vector<std::shared_ptr<NodeBT>> children,
        ParallelPolicy policy = ParallelPolicy::RequireAllSuccess);

    NodeState Tick(float dt, BlackBoard& bb) override;
    void AddChild(std::shared_ptr<NodeBT> child);
    void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) override;

private:
    std::vector<std::shared_ptr<NodeBT>> m_children;
    ParallelPolicy m_policy;
};
