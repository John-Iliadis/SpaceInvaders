//
// Created by Gianni on 31/12/2023.
//

#include "../../include/game_states/pause_state.hpp"

PauseState::PauseState(StateStack &state_stack, Context& context)
        : State(state_stack, context)
{
    auto window_size = context.window->getSize();

    overlay.setSize({(float)window_size.x, (float)window_size.y});
    overlay.setFillColor({0, 0, 0, 128});

    setup_gui(window_size);
    gui_container.select_first();
}

void PauseState::render()
{
    auto window = context.window;

    window->draw(overlay);

    if (is_current)
    {
        window->draw(gui_container);
    }
}

bool PauseState::update()
{
    return false;
}

bool PauseState::handle_event(const sf::Event &event)
{
    gui_container.handle_event(event);
    return false;
}

void PauseState::setup_gui(sf::Vector2u window_size)
{
    GUI_Builder builder;

    auto resume = builder.set_text("RESUME")
            .set_position(window_size.x / 2.f, 300)
            .set_callback_1([this] () {
                request_stack_pop();
            })
            .make_button();

    builder.clear();

    // TODO: Implement after making the game state
    auto restart = builder.set_text("RESTART")
            .set_position(window_size.x / 2.f, 400)
            .set_callback_1(nullptr)
            .make_button();

    builder.clear();

    auto settings = builder.set_text("SETTINGS")
            .set_position(window_size.x / 2.f, 500)
            .set_callback_1([this] () {
                request_stack_push(StateID::SETTINGS);
            })
            .make_button();

    builder.clear();

    auto quit_to_menu = builder.set_text("QUIT TO MENU")
            .set_position(window_size.x / 2.f, 600)
            .set_callback_1([this] () {
                request_state_clear();
                request_stack_push(StateID::MENU);
            })
            .make_button();

    builder.clear();

    auto quit_to_desktop = builder.set_text("QUIT TO DESKTOP")
            .set_position(window_size.x / 2.f, 700)
            .set_callback_1([this] () {context.window->close();})
            .make_button();

    builder.clear();

    gui_container.pack(resume);
    gui_container.pack(restart);
    gui_container.pack(settings);
    gui_container.pack(quit_to_menu);
    gui_container.pack(quit_to_desktop);
}