//
// Created by Gianni on 1/01/2024.
//

#include "../../include/entities/input_handler.hpp"


InputHandler::InputHandler(Context& context)
{
    load_bindings();

    actions[Action::MoveLeft] = [&context] ()
    {
        auto player = context.player;
        player->move(-player->get_velocity().x, 0);
    };

    actions[Action::MoveRight] = [&context] ()
    {
        auto player = context.player;
        player->move(player->get_velocity().x, 0);
    };

    actions[Action::Shoot] = [&context] () {
        context.player->shoot();
    };
}

void InputHandler::handle_event(const sf::Event &event)
{
//    if (event.type != sf::Event::KeyPressed) return;
//
//    if (auto result = bindings.find(event.key.code);
//        result != bindings.end() && !is_real_time_event(result->second))
//    {
//        actions[result->second]();
//    }
}

void InputHandler::handle_real_time_input()
{
    for (auto [key, action] : bindings)
    {
        if (sf::Keyboard::isKeyPressed(key) && is_real_time_event(action))
        {
            actions[action]();
        }
    }
}

void InputHandler::load_bindings()
{
    bindings[KeyBindings::get_move_left()] = Action::MoveLeft;
    bindings[KeyBindings::get_move_right()] = Action::MoveRight;
    bindings[KeyBindings::get_shoot()] = Action::Shoot;
}

bool InputHandler::is_real_time_event(InputHandler::Action action)
{
    switch (action)
    {
        case Action::MoveLeft:
        case Action::MoveRight:
        case Action::Shoot:
            return true;
    }

    throw std::runtime_error("InputHandler::is_real_time_event - Key not covered\n");
}
