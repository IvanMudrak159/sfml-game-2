#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:

public:
    Player(std::string name, GameWorld& gameWorld);
};
