//
// Created by Gianni on 22/12/2023.
//

#include "../../include/game_states/key_binding_state.hpp"

KeyBindingState::KeyBindingState(StateStack &state_stack, sf::RenderWindow &window)
    : State(state_stack, window)
{
    press_any_key.setTexture(Textures::get("press_any_key"));
    press_any_key.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    press_any_key.setScale(1.4, 1.4);
    center_sprite(press_any_key);
}

void KeyBindingState::render()
{
    window.draw(press_any_key);
}

bool KeyBindingState::update()
{
    return false;
}

bool KeyBindingState::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        request_stack_pop();
        request_stack_push(StateID::SETTINGS);
        KeyBindings::set_key(event.key.code);
        KeyBindings::set_key_binding_event(KeyBindings::NONE);
        KeyBindings::save();
    }

    return false;
}

bool KeyBindingState::is_valid_key(sf::Keyboard::Key key)
{
    return false;
}
