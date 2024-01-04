//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_PROJECTILE_HPP
#define SPACEINVADERS_PROJECTILE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "../entities/entity.hpp"
#include "../entities/movable_object.hpp"

class Projectile : public Entity, public MovableObject
{
public:
    enum class Type
    {
        Player,
        Alien
    };

    Projectile(Type type, sf::Vector2f pos)
        : Entity(pos)
        , type(type)
    {
    }

    Type get_type() const {return type;}

protected:
    Type type;
};


#endif //SPACEINVADERS_PROJECTILE_HPP
