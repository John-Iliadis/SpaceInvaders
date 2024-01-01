//
// Created by Gianni on 31/12/2023.
//

#ifndef SPACEINVADERS_PAUSE_STATE_HPP
#define SPACEINVADERS_PAUSE_STATE_HPP


#include <SFML/Graphics/RectangleShape.hpp>
#include "../GUI/gui_includes.hpp"
#include "state.hpp"


class PauseState : public State
{
public:
    PauseState(StateStack& state_stack, Context context);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event &event) override;

private:
    void setup_gui(sf::Vector2u window_size);

private:
    sf::RectangleShape overlay;
    GUI_Container gui_container;
};


#endif //SPACEINVADERS_PAUSE_STATE_HPP
