//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_STATE_HPP
#define SPACEINVADERS_STATE_HPP

namespace sf
{
    class Event;
    class RenderWindow;
}

class StateStack;
enum class StateID;

class State
{
public:
    State(StateStack& state_stack, sf::RenderWindow& window);
    virtual ~State() = default;

    virtual void render() = 0;
    virtual bool update() = 0;
    virtual bool handle_event(const sf::Event& event) = 0;

protected:
    void request_stack_push(StateID state_id);
    void request_stack_pop();
    void request_state_clear();

protected:
    sf::RenderWindow& window;

private:
    StateStack& state_stack;
};


#endif //SPACEINVADERS_STATE_HPP
