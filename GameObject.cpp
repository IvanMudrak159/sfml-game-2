#include "GameObject.h"

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& c : components)
    {
        if (auto drawable = dynamic_cast<sf::Drawable*>(c.get()))
        {
            target.draw(*drawable, states);
        }
    }
}
