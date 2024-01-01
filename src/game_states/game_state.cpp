//
// Created by Gianni on 31/12/2023.
//

#include "../../include/game_states/game_state.hpp"


GameState::GameState(StateStack &state_stack, Context context)
    : State(state_stack, context)
{

}

void GameState::render()
{

}

bool GameState::update()
{
    return false;
}

bool GameState::handle_event(const sf::Event &event)
{
    return false;
}
