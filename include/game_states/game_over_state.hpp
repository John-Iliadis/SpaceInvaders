//
// Created by Gianni on 30/12/2023.
//

#ifndef SPACEINVADERS_GAME_OVER_STATE_HPP
#define SPACEINVADERS_GAME_OVER_STATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "../asset_manager.hpp"
#include "../GUI/gui_includes.hpp"
#include "state.hpp"
#include "../utilities.hpp"

class GameOverState : public State
{
public:
    GameOverState(StateStack& state_stack, sf::RenderWindow& window);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    void build_gui(sf::Vector2u window_size);

private:
    sf::Sprite game_over;
    GUI_Container gui_container;
};


#endif //SPACEINVADERS_GAME_OVER_STATE_HPP
