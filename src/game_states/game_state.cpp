//
// Created by Gianni on 31/12/2023.
//

#include "../../include/game_states/game_state.hpp"


GameState::GameState(StateStack &state_stack, Context& context)
    : State(state_stack, context)
    , world(context)
    , input_handler(context)
{
}

void GameState::on_return()
{
    State::on_return();
    input_handler.load_bindings();
}

void GameState::render()
{
    world.render();
}

bool GameState::update()
{
    input_handler.handle_real_time_input();
    world.update();
    return false;
}

bool GameState::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            request_stack_push(StateID::PAUSE);
        }
    }

    input_handler.handle_event(event);
    world.handle_event(event);
    return false;
}
