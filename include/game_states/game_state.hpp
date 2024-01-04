//
// Created by Gianni on 31/12/2023.
//

#ifndef SPACEINVADERS_GAME_STATE_HPP
#define SPACEINVADERS_GAME_STATE_HPP

#include "state.hpp"
#include "../world.hpp"
#include "../entities/input_handler.hpp"

class GameState : public State
{
public:
    GameState(StateStack& state_stack, Context& context);

    void on_return() override;

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event &event) override;

private:
    World world;
    InputHandler input_handler;
};


#endif //SPACEINVADERS_GAME_STATE_HPP
