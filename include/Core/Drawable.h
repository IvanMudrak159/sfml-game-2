#pragma once
#include <SFML/Graphics/Drawable.hpp>

class Drawable : public sf::Drawable
{
private:
	int layer;

public:
	Drawable(int layer); 

	int GetLayer() const;
};