//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_ENTITY_HPP
#define SPACEINVADERS_ENTITY_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>


class Entity : public sf::Drawable
{
public:
    Entity() = default;
    Entity(sf::Vector2f pos) {sprite.setPosition(pos);}
    virtual ~Entity() = default;

    void set_position(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void set_position(sf::Vector2f pos)
    {
        sprite.setPosition(pos);
    }

    virtual void update() = 0;

    virtual sf::FloatRect get_rect() const {return sprite.getGlobalBounds();};
    sf::Vector2f get_position() const {return sprite.getPosition();}

protected:
    sf::Sprite sprite;
};


#endif //SPACEINVADERS_ENTITY_HPP
