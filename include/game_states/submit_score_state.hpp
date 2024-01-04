//
// Created by Gianni on 31/12/2023.
//

#ifndef SPACEINVADERS_SUBMIT_SCORE_STATE_HPP
#define SPACEINVADERS_SUBMIT_SCORE_STATE_HPP

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include "state.hpp"
#include "../asset_manager.hpp"
#include "../settings/audio/sound_player.hpp"
#include "../utilities.hpp"

class SubmitScoreState : public State
{
public:
    SubmitScoreState(StateStack& state_stack, Context& context);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    void setup_gui();

private:
    sf::RectangleShape background;
    sf::RectangleShape rect;
    sf::Text text;
    sf::Text instruction_msg;
    sf::Text submit;
    sf::Text invalid_name;
    sf::Clock timer;
    std::string input_string;
    bool is_invalid_name;
};


#endif //SPACEINVADERS_SUBMIT_SCORE_STATE_HPP
