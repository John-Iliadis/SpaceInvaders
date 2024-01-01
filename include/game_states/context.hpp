//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_CONTEXT_HPP
#define SPACEINVADERS_CONTEXT_HPP

#include <SFML/Graphics/RenderWindow.hpp>

struct Context
{
    sf::RenderWindow* window;

    Context(sf::RenderWindow* window = nullptr)
        : window(window)
    {
    }
};

#endif //SPACEINVADERS_CONTEXT_HPP
