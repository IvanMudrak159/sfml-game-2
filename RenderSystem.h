#pragma once
#include <vector>

class Drawable;

namespace sf
{
	class Drawable;
	class RenderWindow;
}

class RenderSystem
{
private:
	std::vector<Drawable*> drawables;
	sf::RenderWindow& window;

public:
	RenderSystem(sf::RenderWindow& window);
	~RenderSystem();
	void update();
	void RegisterGameObject(Drawable* drawable);
	void UnregisterGameObject(Drawable* drawable);
	sf::RenderWindow& getWindow() const { return window; }

};
