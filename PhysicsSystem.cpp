#include "PhysicsSystem.h"

#include <iostream>

void PhysicsSystem::resolveCollision(BoxCollider* a, BoxCollider* b)
{
    RigidBody* ra = a->owner->getComponent<RigidBody>();
    RigidBody* rb = b->owner->getComponent<RigidBody>();

    if (!ra && !rb) return;

    auto intersectionOpt = a->getWorldBounds().findIntersection(b->getWorldBounds());
    if (!intersectionOpt) return;

    sf::FloatRect inter = intersectionOpt.value();

    sf::Vector2f aCenter(
        a->getWorldBounds().position.x + a->getWorldBounds().size.x / 2.f,
        a->getWorldBounds().position.y + a->getWorldBounds().size.y / 2.f
    );

    sf::Vector2f bCenter(
        b->getWorldBounds().position.x + b->getWorldBounds().size.x / 2.f,
        b->getWorldBounds().position.y + b->getWorldBounds().size.y / 2.f
    );

    sf::Vector2f mtv;

    if (inter.size.x < inter.size.y)
    {
        if (aCenter.x < bCenter.x)
            mtv = sf::Vector2f(-inter.size.x, 0.f);
        else
            mtv = sf::Vector2f(inter.size.x, 0.f);
    }
    else
    {
        if (aCenter.y < bCenter.y)
            mtv = sf::Vector2f(0.f, -inter.size.y);
        else
            mtv = sf::Vector2f(0.f, inter.size.y); 
    }

    if (ra && ra->type == RigidbodyType::Dynamic && (!rb || rb->type != RigidbodyType::Dynamic))
    {
        a->owner->move(mtv);
        ra->velocity = { 0.f, 0.f };
    }
    else if (rb && rb->type == RigidbodyType::Dynamic && (!ra || ra->type != RigidbodyType::Dynamic))
    {
        b->owner->move(-mtv);
        rb->velocity = { 0.f, 0.f };
    }
}

PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
    colliders.clear();
}

void PhysicsSystem::Register(BoxCollider* collider)
{
    colliders.push_back(collider);
}

void PhysicsSystem::Unregister(BoxCollider* collider)
{
    colliders.erase(
        std::remove(colliders.begin(), colliders.end(), collider),
        colliders.end()
    );
}

void PhysicsSystem::Register(RigidBody* rigidBody)
{
    rigidBodies.push_back(rigidBody);
}

void PhysicsSystem::Unregister(RigidBody* rigidBody)
{
    rigidBodies.erase(
        std::remove(rigidBodies.begin(), rigidBodies.end(), rigidBody),
        rigidBodies.end()
    );

}

void PhysicsSystem::update(float dt)
{
    for (RigidBody* rigidBody : rigidBodies)
    {
        rigidBody->update(dt);
    }

    for (BoxCollider* boxCollider : colliders)
    {
        boxCollider->update(dt);
    }

    for (size_t i = 0; i < rigidBodies.size(); ++i)
    {
        for (size_t j = 0; j < colliders.size(); ++j)
        {
            RigidBody* rb = rigidBodies[i];
            BoxCollider* a = rb->owner->getComponent<BoxCollider>();

            if (!a) continue;

            BoxCollider* b = colliders[j];
            if (a == b) continue;

            if (a->getWorldBounds().findIntersection(b->getWorldBounds()))
            {
                std::cout << "FOUND INTERSECTION" << std::endl;
                resolveCollision(a, b);
            }
        }
    }


}
