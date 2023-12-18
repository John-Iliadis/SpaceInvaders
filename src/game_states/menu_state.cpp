//
// Created by Gianni on 18/12/2023.
//

#include "../../include/game_states/menu_state.hpp"

MenuState::MenuState(StateStack& state_stack, sf::RenderWindow &window)
    : State(state_stack, window)
{
    background.setTexture(Textures::get("menu_background"));
    background.setScale(0.5, 0.5);
}

void MenuState::render()
{
    window.draw(background);
}

bool MenuState::update()
{
    return true;
}

bool MenuState::handle_event(const sf::Event &event)
{
    return true;
}
