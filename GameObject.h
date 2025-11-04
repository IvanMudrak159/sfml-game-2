#pragma once
#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Drawable.h"
#include "Component.h"

class GameWorld;


class GameObject : public sf::Transformable, public Drawable
{
public:
    GameObject(std::string name, GameWorld& gameWorld);
    ~GameObject() override;
    void update(float dt) const;

    std::vector<std::unique_ptr<Component>> components;
    std::string name;

    template<typename T, typename... Args>
    T* addComponent(Args&&... args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        auto comp = std::make_unique<T>(this, std::forward<Args>(args)...);
        T* ptr = comp.get();

        components.push_back(std::move(comp));

        if (auto drawable = dynamic_cast<Drawable*>(ptr))
        {
            this->gameWorld.getRenderSystem().RegisterGameObject(drawable);
        }

        return ptr;
    }

    template<typename T>
    bool removeComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        // reverse iterate but erase using base iterator
        for (auto it = components.rbegin(); it != components.rend(); ++it)
        {
            if (dynamic_cast<T*>(it->get()))
            {
                Component* comp = it->get();

                // Unregister drawable if needed
                if (auto drawable = dynamic_cast<Drawable*>(comp))
                {
                    gameWorld.getRenderSystem().UnregisterGameObject(drawable);
                }

                // convert reverse_iterator to regular iterator
                auto baseIt = std::next(it).base();
                components.erase(baseIt); // unique_ptr deleted -> component destroyed
                return true;
            }
        }
        return false;
    }


    template<typename T>
    T* getComponent() const
    {
        for (auto& c : components)
        {
	        if (T* ptr = dynamic_cast<T*>(c.get()))
                return ptr;
        }
        return nullptr;
    }

    bool hasCollider() const;


    GameWorld* getGameWorld() const;

protected:
    GameWorld& gameWorld;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
