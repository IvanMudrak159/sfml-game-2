#include "DebugHighlighter.h"

#include "GameObject.h"

DebugHighlighter::DebugHighlighter(GameObject* owner, sf::Vector2f position, sf::Vector2f size, sf::Color color) : Component(owner),
                                                                                                  Drawable(9999)
{
	debugRect.setSize(size);
	debugRect.setPosition(position);
	debugRect.setFillColor(sf::Color::Transparent);
	debugRect.setOutlineColor(color);
	debugRect.setOutlineThickness(1.f);

}

void DebugHighlighter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(debugRect, states);
}
