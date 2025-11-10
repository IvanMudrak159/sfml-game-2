#pragma once
#include "Core/GameObject.h"

class Level;

class Player : public GameObject
{
private:

public:
    Player(std::string name, GameWorld& gameWorld, Level* level);
};
