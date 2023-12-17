//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_GAME_HPP
#define SPACEINVADERS_GAME_HPP

#include <SFML/Graphics.hpp>

#include "asset_manager.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void handle_events();
    void update();
    void render();

private:
    sf::RenderWindow window;
};


#endif //SPACEINVADERS_GAME_HPP
