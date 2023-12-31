//
// Created by Gianni on 30/12/2023.
//

#include "../../include/game_states/game_over_state.hpp"

GameOverState::GameOverState(StateStack &state_stack, sf::RenderWindow &window)
    : State(state_stack, window)
{
    auto window_size = window.getSize();
    game_over.setTexture(Textures::get("game_over"));
    game_over.setPosition(window_size.x / 2.f, 150);
    game_over.setScale(1.5, 1.5);
    center_sprite(game_over);

    build_gui(window_size);

    gui_container.select_first();
}

void GameOverState::render()
{
    window.draw(game_over);
    window.draw(gui_container);
}

bool GameOverState::update()
{
    return false;
}

bool GameOverState::handle_event(const sf::Event &event)
{
    gui_container.handle_event(event);
    return false;
}

void GameOverState::build_gui(sf::Vector2u window_size)
{
    GUI_Builder builder;

    auto restart = builder.set_text("RESTART")
           .set_position(window_size.x / 2.f, 450)
           .set_callback_1(nullptr)
           .make_button();

    builder.clear();

    auto submit_score = builder.set_text("SUBMIT SCORE")
           .set_position(window_size.x / 2.f, 550)
           .set_callback_1([this] () {
               request_stack_push(StateID::SUBMIT_SCORE);
           })
           .make_button();

    builder.clear();

    auto exit = builder.set_text("EXIT")
           .set_position(window_size.x / 2.f, 650)
           .set_callback_1([this] () {
               request_stack_pop();
               request_stack_push(StateID::MENU);})
           .make_button();

    builder.clear();

    gui_container.pack(restart);
    gui_container.pack(submit_score);
    gui_container.pack(exit);
}
