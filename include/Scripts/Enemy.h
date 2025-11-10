#pragma once
#include "Core/GameObject.h"
#include "Levels/Level.h"

class Enemy : public GameObject
{
public:
	Enemy(const std::string& name, GameWorld& gameWorld, const Level* level);
};
