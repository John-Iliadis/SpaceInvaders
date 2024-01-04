//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_MOVABLE_OBJECT_HPP
#define SPACEINVADERS_MOVABLE_OBJECT_HPP

#include <SFML/System/Vector2.hpp>

class MovableObject
{
public:
    MovableObject() = default;
    MovableObject(float x, float y);
    MovableObject(sf::Vector2f velocity);
    virtual ~MovableObject() = default;

    void set_velocity(float x, float y);
    void set_velocity(sf::Vector2f velocity);

    sf::Vector2f get_velocity() const;

    virtual void move(float x, float y) {};

protected:
    sf::Vector2f velocity;
};


#endif //SPACEINVADERS_MOVABLE_OBJECT_HPP
