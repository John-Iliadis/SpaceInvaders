//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_GAME_HPP
#define SPACEINVADERS_GAME_HPP

#include <SFML/Graphics.hpp>

#include "asset_manager.hpp"
#include "sound_player.hpp"
#include "game_states/state_stack.hpp"
#include "game_states/menu_state.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void handle_events();
    void update();
    void render();

    void register_game_states();

private:
    sf::RenderWindow window;
    StateStack state_stack;
};


#endif //SPACEINVADERS_GAME_HPP
