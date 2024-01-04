//
// Created by Gianni on 1/01/2024.
//

#include "../../include/entities/movable_object.hpp"

MovableObject::MovableObject(float x, float y)
    : velocity(x, y)
{
}

MovableObject::MovableObject(sf::Vector2f velocity)
    : velocity(velocity)
{
}

void MovableObject::set_velocity(float x, float y)
{
    velocity = {x, y};
}

void MovableObject::set_velocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}

sf::Vector2f MovableObject::get_velocity() const
{
    return velocity;
}
