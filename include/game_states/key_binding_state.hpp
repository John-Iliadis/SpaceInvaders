//
// Created by Gianni on 22/12/2023.
//

#ifndef SPACEINVADERS_KEY_BINDING_STATE_HPP
#define SPACEINVADERS_KEY_BINDING_STATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "state.hpp"
#include "../utilities.hpp"
#include "../asset_manager.hpp"
#include "../settings/key_bindings.hpp"


class KeyBindingState : public State
{
public:
    KeyBindingState(StateStack& state_stack, sf::RenderWindow& window);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    bool is_valid_key(sf::Keyboard::Key key);

private:
    sf::Sprite press_any_key;
};


#endif //SPACEINVADERS_KEY_BINDING_STATE_HPP
