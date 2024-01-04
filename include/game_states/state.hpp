//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_STATE_HPP
#define SPACEINVADERS_STATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "context.hpp"
#include "state_identifiers.hpp"

class StateStack;

class State
{
public:
    State(StateStack& state_stack, Context& context);
    virtual ~State() = default;

    virtual void on_exit();
    virtual void on_return();

    virtual void render() = 0;
    virtual bool update() = 0;
    virtual bool handle_event(const sf::Event& event) = 0;

protected:
    void request_stack_push(StateID state_id);
    void request_stack_pop();
    void request_state_clear();

protected:
    Context& context;
    bool is_current;

private:
    StateStack& state_stack;
};


#endif //SPACEINVADERS_STATE_HPP
