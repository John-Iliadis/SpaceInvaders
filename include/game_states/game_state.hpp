//
// Created by Gianni on 31/12/2023.
//

#ifndef SPACEINVADERS_GAME_STATE_HPP
#define SPACEINVADERS_GAME_STATE_HPP

#include "state.hpp"


class GameState : public State
{
public:
    GameState(StateStack& state_stack, Context context);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event &event) override;

private:
};


#endif //SPACEINVADERS_GAME_STATE_HPP
