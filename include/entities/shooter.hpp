//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_SHOOTER_HPP
#define SPACEINVADERS_SHOOTER_HPP

#include <SFML/System/Vector2.hpp>

class Shooter
{
public:
    Shooter() = default;
    virtual ~Shooter() = default;

    virtual sf::Vector2f get_shooting_pos() const = 0;
};


#endif //SPACEINVADERS_SHOOTER_HPP
