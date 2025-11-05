#pragma once
#include "GameObject.h"

class BehaviourTree;
class Level;

class Enemy : public GameObject
{
public:
	Enemy(std::string name, GameWorld& gameWorld, Level* level);
};
