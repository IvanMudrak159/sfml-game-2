#pragma once
#include "GameWorld.h"

class GameObject;

class Component
{

public:
    Component(GameObject* owner) : owner(owner) {}
    virtual ~Component() = default;
    virtual void Update(float dt) {}

    GameObject* owner;
};
