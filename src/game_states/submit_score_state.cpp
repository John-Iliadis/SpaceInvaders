//
// Created by Gianni on 31/12/2023.
//

#include "../../include/game_states/submit_score_state.hpp"


SubmitScoreState::SubmitScoreState(StateStack &state_stack, Context& context)
    : State(state_stack, context)
{
    setup_gui();

    is_invalid_name = true;
}

void SubmitScoreState::render()
{
    auto window = context.window;

    window->draw(background);
    window->draw(instruction_msg);
    window->draw(rect);
    window->draw(text);
    window->draw(submit);

    if (!is_invalid_name)
    {
        window->draw(invalid_name);

        if (timer.getElapsedTime().asSeconds() > 2.5)
        {
            is_invalid_name = true;
            timer.restart();
        }
    }
}

bool SubmitScoreState::update()
{
    return false;
}

bool SubmitScoreState::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::TextEntered)
    {
        auto unicode = event.text.unicode;

        if (unicode == 8 && !input_string.empty())
        {
            input_string.pop_back();
        }
        else if (unicode != 13 && unicode != 8 && input_string.length() < 14)
        {
            input_string += static_cast<char>(unicode);
        }

        text.setString("Enter your name: " + input_string);
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            if (input_string.length() < 2)
            {
                is_invalid_name = false;
                timer.restart();
            }
            else
            {
                SoundPlayer::play("pick");
                request_stack_pop();

                // rest of logic here
            }
        }
    }

    return false;
}

void SubmitScoreState::setup_gui()
{
    auto window_size = context.window->getSize();

    background.setSize({(float)window_size.x, (float)window_size.y});
    background.setFillColor(sf::Color::Black);

    rect.setSize({800, 140});
    rect.setFillColor(sf::Color::White);
    rect.setPosition(window_size.x / 2.f, 400);
    rect.setOutlineThickness(10);
    rect.setOutlineColor(sf::Color::Red);
    center_shape(rect);

    auto rect_rect = rect.getGlobalBounds();

    text.setString("Enter your name: ");
    text.setFont(Fonts::get("pixel_type"));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(rect_rect.left + 20, rect_rect.top + rect_rect.height / 2.f);
    set_text_origin_left(text);

    instruction_msg.setFont(Fonts::get("pixel_type"));
    instruction_msg.setString("A name should be between 2-14 letters");
    instruction_msg.setFillColor(sf::Color::White);
    instruction_msg.setCharacterSize(35);
    instruction_msg.setPosition(window_size.x / 2.f, 270);
    center_text(instruction_msg);

    submit.setFont(Fonts::get("pixel_type"));
    submit.setString("SUBMIT");
    submit.setCharacterSize(148);
    submit.setPosition(window_size.x / 2.f, 700);
    submit.setFillColor(sf::Color::Yellow);
    center_text(submit);

    invalid_name.setFont(Fonts::get("pixel_type"));
    invalid_name.setString("INVALID NAME");
    invalid_name.setPosition(window_size.x / 2.f, 520);
    invalid_name.setCharacterSize(70);
    invalid_name.setFillColor(sf::Color::Red);
    center_text(invalid_name);
}
