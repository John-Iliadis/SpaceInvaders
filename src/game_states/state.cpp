//
// Created by Gianni on 18/12/2023.
//

#include "../../include/game_states/state.hpp"
#include "../../include/game_states/state_stack.hpp"

State::State(StateStack &state_stack, Context& context)
    : state_stack(state_stack)
    , context(context)
    , is_current(true)
{
}

void State::on_return()
{
    is_current = true;
}

void State::on_exit()
{
    is_current = false;
}

void State::request_stack_push(StateID state_id)
{
    state_stack.push_state(state_id);
}

void State::request_stack_pop()
{
    state_stack.pop_state();
}

void State::request_state_clear()
{
    state_stack.clear_states();
}

