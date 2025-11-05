#include "BehaviourTree.h"
#include "NodeBT.h"

BehaviourTree::BehaviourTree(GameObject* owner, std::shared_ptr<NodeBT> root): Component(owner), m_root(root)
{
}

void BehaviourTree::Update(float dt)
{
	Component::Update(dt);
	m_root->Tick(dt);
}
