//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_STATE_STACK_HPP
#define SPACEINVADERS_STATE_STACK_HPP

#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>
#include <ranges>
#include <type_traits>

#include <SFML/Window/Event.hpp>

#include "state.hpp"
#include "state_identifiers.hpp"


class StateStack
{
public:
    StateStack(sf::RenderWindow& window);

    template<typename state_type>
    void register_state(StateID state_id);

    void update();
    void render();
    void handle_event(const sf::Event& event);

    void push_state(StateID state_id);
    void pop_state();
    void clear_states();

    bool is_empty() const;

private:
    enum class Action
    {
        PUSH,
        POP,
        CLEAR
    };

    struct PendingChange
    {
        Action action;
        StateID state_id;
    };

private:
    void apply_pending_changes();
    std::unique_ptr<State> create_state(StateID state_id);

private:
    std::vector<std::unique_ptr<State>> state_stack;
    std::vector<PendingChange> pending_changes;
    std::unordered_map<StateID, std::function<std::unique_ptr<State>()>> state_factory;

    sf::RenderWindow& window;
};

template<typename state_type>
void StateStack::register_state(StateID state_id)
{
    if constexpr (!std::is_base_of<State, state_type>::value)
    {
        throw std::runtime_error("StateStack::register_state - Given state_type not derived from State class\n");
    }

    state_factory[state_id] = [this] () {
        return std::make_unique<state_type>(*this, window);
    };
}


#endif //SPACEINVADERS_STATE_STACK_HPP
