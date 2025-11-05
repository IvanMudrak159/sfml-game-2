#pragma once
#include <memory>
#include "Component.h"

class NodeBT;

class BehaviourTree : public Component
{
public:
    BehaviourTree(GameObject* owner, std::shared_ptr<NodeBT> root);
    void Update(float dt) override;

private:
    std::shared_ptr<NodeBT> m_root;
};
