//
// Created by Gianni on 30/12/2023.
//

#include "../../include/game_states/high_scores_state.hpp"

HighScoresState::HighScoresState(StateStack &state_stack, Context context)
    : State(state_stack, context)
{
    auto win_size = context.window->getSize();

    background.setTexture(Textures::get("menu_background"));
    background.setScale(0.5, 0.5);

    high_scores.setFont(Fonts::get("pixel_type"));
    high_scores.setString("HIGH SCORES");
    high_scores.setCharacterSize(220);
    high_scores.setFillColor({200, 0, 0});
    high_scores.setPosition(win_size.x / 2.f, 115);
    center_text(high_scores);

    back_to_menu.setFont(Fonts::get("pixel_type"));
    back_to_menu.setString("PRESS ENTER TO RETURN TO MENU");
    back_to_menu.setCharacterSize(60);
    back_to_menu.setFillColor(sf::Color::Yellow);
    back_to_menu.setPosition(win_size.x / 2.f, win_size.y - 50);
    center_text(back_to_menu);

    rank.setFont(Fonts::get("pixel_type"));
    rank.setString("RANK");
    rank.setCharacterSize(100);
    rank.setFillColor({100, 100, 100});
    rank.setPosition(win_size.x / 5.f, 250);
    set_text_origin_right(rank);

    name.setFont(Fonts::get("pixel_type"));
    name.setString("NAME");
    name.setCharacterSize(100);
    name.setFillColor({100, 100, 100});
    name.setPosition(win_size.x / 5.f + 80.f, 250);
    set_text_origin_left(name);

    score.setFont(Fonts::get("pixel_type"));
    score.setString("SCORE");
    score.setCharacterSize(100);
    score.setFillColor({100, 100, 100});
    score.setPosition(930, 250);
    set_text_origin_left(score);

    const auto& high_scores_values = HighScores::get_scores();

    scores.reserve(10);

    float initial_y = 250;

    for (int i = 0; i < high_scores_values.size() && i <= 10; ++i)
    {
        sf::Text rank;
        sf::Text name;
        sf::Text score;

        rank.setFont(Fonts::get("pixel_type"));
        name.setFont(Fonts::get("pixel_type"));
        score.setFont(Fonts::get("pixel_type"));

        rank.setString(std::to_string(i + 1) + ".");
        name.setString(high_scores_values.at(i).first);
        score.setString(std::to_string(high_scores_values.at(i).second));

        rank.setCharacterSize(80);
        name.setCharacterSize(80);
        score.setCharacterSize(80);

        rank.setPosition(win_size.x / 5.f, initial_y + (i + 1) * 60);
        name.setPosition(win_size.x / 5.f + 80.f, initial_y + (i + 1) * 60);
        score.setPosition(930, initial_y + (i + 1) * 60);

        score.setFillColor(sf::Color::Yellow);

        set_text_origin_right(rank);
        set_text_origin_left(name);
        set_text_origin_left(score);

        scores.push_back(std::move(rank));
        scores.push_back(std::move(name));
        scores.push_back(std::move(score));
    }
}

void HighScoresState::render()
{
    auto window = context.window;

    window->draw(background);
    window->draw(high_scores);
    window->draw(back_to_menu);
    window->draw(rank);
    window->draw(name);
    window->draw(score);

    for (const auto& text : scores)
    {
        window->draw(text);
    }
}

bool HighScoresState::update()
{
    return false;
}

bool HighScoresState::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            SoundPlayer::play("pick");
            request_stack_pop();
            request_stack_push(StateID::MENU);
        }
    }

    return false;
}
