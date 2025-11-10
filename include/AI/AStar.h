#pragma once
#include <vector>
class NodeAI;

class AStar
{
public:
    std::vector<NodeAI*> findPath(NodeAI* start, NodeAI* goal);

private:

    float heuristic(NodeAI* a, NodeAI* b);
    float distance(NodeAI* a, NodeAI* b);
    std::vector<NodeAI*> reconstructPath(NodeAI* goal);
};
