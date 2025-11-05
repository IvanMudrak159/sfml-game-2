#pragma once
#include <memory>

#include "BlackBoard.h"
#include "Component.h"
#include "Drawable.h"

class NodeBT;

class BehaviourTree : public Component, public Drawable
{
public:
    BehaviourTree(GameObject* owner, std::shared_ptr<NodeBT> root);
    void Update(float dt) override;
    BlackBoard& GetBlackBoard();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::shared_ptr<NodeBT> m_root;
    BlackBoard m_blackboard;
};
