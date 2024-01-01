//
// Created by Gianni on 30/12/2023.
//

#ifndef SPACEINVADERS_HIGH_SCORES_STATE_HPP
#define SPACEINVADERS_HIGH_SCORES_STATE_HPP

#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "state.hpp"
#include "../high_scores.hpp"
#include "../asset_manager.hpp"
#include "../utilities.hpp"
#include "../settings/audio/sound_player.hpp"

class HighScoresState : public State
{
public:
    HighScoresState(StateStack& state_stack, Context context);

    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    sf::Sprite background;
    sf::Text high_scores;
    sf::Text back_to_menu;
    sf::Text rank;
    sf::Text name;
    sf::Text score;
    std::vector<sf::Text> scores;
};


#endif //SPACEINVADERS_HIGH_SCORES_STATE_HPP
