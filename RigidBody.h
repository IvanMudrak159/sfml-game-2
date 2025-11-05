#pragma once
#include "Component.h"

enum class RigidbodyType
{
    Static,
    Dynamic,
    Kinematic
};


class RigidBody : public Component
{
public:
    RigidbodyType type;
    sf::Vector2f velocity;
    float mass;

    RigidBody(GameObject* owner, RigidbodyType t = RigidbodyType::Dynamic, float m = 1.f);
    ~RigidBody() override;
    void applyForce(const sf::Vector2f& force);
    void setConstForce(const sf::Vector2f& force);
    void Update(float dt) override;
    
};
