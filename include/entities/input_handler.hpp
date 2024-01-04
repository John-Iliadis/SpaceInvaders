//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_INPUT_HANDLER_HPP
#define SPACEINVADERS_INPUT_HANDLER_HPP

#include <unordered_map>
#include <functional>
#include <SFML/Window/Event.hpp>
#include "player.hpp"
#include "../settings/key_bindings.hpp"
#include "../game_states/context.hpp"


class InputHandler
{
public:
    InputHandler(Context& context);

    void handle_event(const sf::Event& event);
    void handle_real_time_input();

    void load_bindings();

private:
    enum class Action
    {
        MoveLeft,
        MoveRight,
        Shoot
    };

private:
    bool is_real_time_event(Action action);

private:
    std::unordered_map<sf::Keyboard::Key, Action> bindings;
    std::unordered_map<Action, std::function<void()>> actions;
};


#endif //SPACEINVADERS_INPUT_HANDLER_HPP
