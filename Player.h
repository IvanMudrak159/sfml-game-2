#pragma once

#include "GameObject.h"

class Level;

class Player : public GameObject
{
private:

public:
    Player(std::string name, GameWorld& gameWorld, Level* level);
};
