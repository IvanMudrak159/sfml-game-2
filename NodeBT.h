#pragma once
#include <string>
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
    Running,
    ConditionFailed
};

class NodeBT
{
public:
	NodeBT(const std::string& name) : name(name) {}
    virtual ~NodeBT() = default;
    virtual NodeState Tick(float dt, BlackBoard& bb) = 0;
    virtual void DrawDebug(sf::RenderTarget& target, sf::RenderStates states, BlackBoard& bb) {}
    virtual void Reset() {}

protected:
    NodeState state = NodeState::Running;
	std::string name;
};
