#pragma once
#include "GameObject.h"

class BehaviourTree;
class Level;

class Enemy : public GameObject
{
public:
	Enemy(const std::string& name, GameWorld& gameWorld, const Level* level);
};
