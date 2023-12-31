//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_GAME_HPP
#define SPACEINVADERS_GAME_HPP

#include <SFML/Graphics.hpp>

#include "asset_manager.hpp"
#include "settings/audio/sound_player.hpp"
#include "game_states/state_stack.hpp"
#include "game_states/menu_state.hpp"
#include "game_states/settings_state.hpp"
#include "game_states/key_binding_state.hpp"
#include "game_states/high_scores_state.hpp"
#include "game_states/game_over_state.hpp"
#include "game_states/submit_score_state.hpp"
#include "settings/audio/sound_player.hpp"
#include "settings/audio/music_player.hpp"

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
