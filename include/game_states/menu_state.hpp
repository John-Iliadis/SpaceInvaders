//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_MENU_STATE_HPP
#define SPACEINVADERS_MENU_STATE_HPP

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "../asset_manager.hpp"

class MenuState : public State
{
public:
    MenuState(StateStack& state_stack, sf::RenderWindow& window);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    sf::Sprite background;
};


#endif //SPACEINVADERS_MENU_STATE_HPP
