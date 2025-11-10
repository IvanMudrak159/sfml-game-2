#include "Scripts/Player.h"

#include <string>

#include "AI/AgentAI.h"
#include "Components/SpriteRenderer.h"
#include "Core/GameWorld.h"
#include "Levels/Level.h"
#include "Scripts/PlayerController.h"
#include "Core/GameObject.h"

Player::Player(std::string name, GameWorld& gameWorld, Level* level)
	: GameObject(name, gameWorld)
{
    addComponent<SpriteRenderer>("Sprites/player.png", sf::Vector2i(32, 32), 5);
    addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));

    addComponent<AgentAI>( *level->GetMapAI());


    RigidBody* rb = addComponent<RigidBody>();
    addComponent<PlayerController>(*rb, level);
}
