#pragma once
#include <SFML/Graphics/RenderStates.hpp>


class BlackBoard;
class BehaviourTree;

namespace sf
{
	class RenderTarget;
}

enum class NodeState
{
    Success,
    Failure,
    Running
};

class NodeBT
{
public:
    virtual ~NodeBT() = default;
    virtual NodeState Tick(float dt, BlackBoard& bb) = 0;
    virtual void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) {}

protected:
    NodeState state = NodeState::Running;
};
