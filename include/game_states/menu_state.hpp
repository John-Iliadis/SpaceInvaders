//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_MENU_STATE_HPP
#define SPACEINVADERS_MENU_STATE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "../asset_manager.hpp"
#include "../GUI/gui_includes.hpp"

class MenuState : public State
{
public:
    MenuState(StateStack& state_stack, sf::RenderWindow& window);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    void setup_gui(sf::Vector2u window_size);

private:
    sf::Sprite background;
    sf::Sprite title;

    GUI_Container gui_container;
};


#endif //SPACEINVADERS_MENU_STATE_HPP
