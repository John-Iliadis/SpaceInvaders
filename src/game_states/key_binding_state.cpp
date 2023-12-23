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

    invalid_key.setString("Invalid Key");
    invalid_key.setFont(Fonts::get("pixel_type"));
    invalid_key.setCharacterSize(100);
    invalid_key.setFillColor({255, 0, 0});
    invalid_key.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 200);
    center_text(invalid_key);

    show_invalid_key = false;
}

void KeyBindingState::render()
{
    window.draw(press_any_key);

    show_invalid_key? window.draw(invalid_key) : (void)0;
}

bool KeyBindingState::update()
{
    return false;
}

bool KeyBindingState::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (!is_valid_key(event.key.code))
        {
            show_invalid_key = true;
        }
        else
        {
            request_stack_pop();
            request_stack_push(StateID::SETTINGS);
            KeyBindings::set_key(event.key.code);
            KeyBindings::set_key_binding_event(KeyBindings::NONE);
            KeyBindings::save();
        }
    }

    return false;
}

bool KeyBindingState::is_valid_key(sf::Keyboard::Key key)
{
    auto left = KeyBindings::get_move_left();
    auto right = KeyBindings::get_move_right();
    auto shoot = KeyBindings::get_shoot();

    switch (KeyBindings::get_key_binding_event())
    {
        case KeyBindings::LEFT:
            if (key == right || key == shoot) return false;
            break;

        case KeyBindings::RIGHT:
            if (key == left || key == shoot) return false;
            break;

        case KeyBindings::SHOOT:
            if (key == left || key == right) return false;
            break;

        case KeyBindings::NONE:
            throw std::runtime_error("KeyBindingState::is_valid_key - KeyBindings::NONE is set\n");
            break;
    }

    return true;
}
