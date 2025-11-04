#include "AStar.h"

#include <queue>
#include <unordered_set>

std::vector<NodeAI*> AStar::findPath(NodeAI* start, NodeAI* goal)
{
    if (!start || !goal) return {};

    auto compare = [](NodeAI* a, NodeAI* b) {
        return a->getF() > b->getF();
        };

    std::priority_queue<NodeAI*, std::vector<NodeAI*>, decltype(compare)> openSet(compare);

    std::unordered_set<NodeAI*> closedSet;

    start->setG(0);
    start->setH(heuristic(start, goal));
    start->setParent(nullptr);

    openSet.push(start);

    while (!openSet.empty())
    {
        NodeAI* current = openSet.top();
        openSet.pop();

        if (current == goal)
            return reconstructPath(goal);

        closedSet.insert(current);

        for (NodeAI* neighbor : current->getNeighbors())
        {
            if (!neighbor->isWalkable() || closedSet.count(neighbor))
                continue;

            float tentativeG = current->getG() + distance(current, neighbor);

            bool isInOpen = false;

            if (tentativeG < neighbor->getG() || neighbor->getParent() == nullptr)
            {
                neighbor->setParent(current);
                neighbor->setG(tentativeG);
                neighbor->setH(heuristic(neighbor, goal));

                openSet.push(neighbor);
            }
        }
    }

    return {};
}

float AStar::heuristic(NodeAI* a, NodeAI* b)
{
    return abs(a->getPosition().x - b->getPosition().x) +
        abs(a->getPosition().y - b->getPosition().y);
}

float AStar::distance(NodeAI* a, NodeAI* b)
{
    sf::Vector2f d = a->getPosition() - b->getPosition();
    return sqrt(d.x * d.x + d.y * d.y);
}

std::vector<NodeAI*> AStar::reconstructPath(NodeAI* goal)
{
    std::vector<NodeAI*> path;
    NodeAI* current = goal;

    while (current != nullptr)
    {
        path.push_back(current);
        current = current->getParent();
    }

    std::reverse(path.begin(), path.end());
    return path;
}