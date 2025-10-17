#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Component.h"


class GameObject : public sf::Transformable, public sf::Drawable
{
public:
    std::vector<std::unique_ptr<Component>> components;

    template<typename T, typename... Args>
    T* addComponent(Args&&... args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        auto comp = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = comp.get();

        ptr->owner = this;

        components.push_back(std::move(comp));
        return ptr;
    }

    template<typename T>
    T* getComponent() const
    {
        for (auto& c : components) {
            if (auto ptr = dynamic_cast<T*>(c.get()))
                return ptr;
        }
        return nullptr;
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};