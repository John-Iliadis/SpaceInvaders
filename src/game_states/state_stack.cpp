//
// Created by Gianni on 18/12/2023.
//

#include "../../include/game_states/state_stack.hpp"

StateStack::StateStack(sf::RenderWindow &window)
    : window(window)
{
}

void StateStack::update()
{
    for (auto& state : std::ranges::views::reverse(state_stack))
    {
        if (!state->update())
            break;
    }

    apply_pending_changes();
}

void StateStack::render()
{
    for (auto& state : state_stack)
        state->render();
}

void StateStack::handle_event(const sf::Event &event)
{
    for (auto& state : std::ranges::views::reverse(state_stack))
    {
        if (!state->handle_event(event))
            break;
    }

    apply_pending_changes();
}

void StateStack::push_state(StateID state_id)
{
    pending_changes.push_back({
        Action::PUSH,
        state_id
    });
}

void StateStack::pop_state()
{
    pending_changes.push_back({
        Action::POP,
        StateID::NONE
    });
}

void StateStack::clear_states()
{
    pending_changes.push_back({
        Action::CLEAR,
        StateID::NONE
    });
}

bool StateStack::is_empty() const
{
    return state_stack.empty();
}

void StateStack::apply_pending_changes()
{
    for (auto [action, state_id] : pending_changes)
    {
        switch (action)
        {
            case Action::PUSH:
                if (!is_empty()) state_stack.back()->on_exit();
                state_stack.push_back(std::move(create_state(state_id)));
                break;

            case Action::POP:
                state_stack.back()->on_exit();
                state_stack.pop_back();
                if (!is_empty()) state_stack.back()->on_return();
                break;

            case Action::CLEAR:
                state_stack.clear();
                break;
        }
    }

    pending_changes.clear();
}

std::unique_ptr<State> StateStack::create_state(StateID state_id)
{
    if (auto pair = state_factory.find(state_id);
        pair != state_factory.end())
    {
        return pair->second();
    }

    throw std::runtime_error("StateStack::create_state - State doesn't exist in state factory\n");
}
