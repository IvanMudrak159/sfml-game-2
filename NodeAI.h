#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

class NodeAI
{
private:
	sf::Vector2f position;
	bool walkable;
	std::vector<NodeAI*> neighbors;

	float gCost = 0;
	float hCost = 0;
    float fCost() const;
	NodeAI* parent = nullptr;

public:
    NodeAI(const sf::Vector2f& pos, bool isWalkable);

    bool isInPath = false;

    // --- Getters ---
    const sf::Vector2f& getPosition() const { return position; }
    bool isWalkable() const { return walkable; }

    const std::vector<NodeAI*>& getNeighbors() const { return neighbors; }
    void addNeighbor(NodeAI* n) { neighbors.push_back(n); }

    // --- A* fields ---
    float getG() const { return gCost; }
    float getH() const { return hCost; }
    float getF() const { return gCost + hCost; }

    void setG(float g) { gCost = g; }
    void setH(float h) { hCost = h; }
    void setParent(NodeAI* p) { parent = p; }
    NodeAI* getParent() const { return parent; }
};
