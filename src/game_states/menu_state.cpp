//
// Created by Gianni on 18/12/2023.
//

#include "../../include/game_states/menu_state.hpp"
#include "../../include/game_states/state_identifiers.hpp"

MenuState::MenuState(StateStack& state_stack, sf::RenderWindow &window)
    : State(state_stack, window)
{
    sf::Vector2u window_size = window.getSize();

    background.setTexture(Textures::get("menu_background"));
    background.setScale(0.5, 0.5);

    auto& title_texture = Textures::get("title");
    title.setOrigin(title_texture.getSize().x / 2.f, title_texture.getSize().y / 2.f);
    title.setTexture(title_texture);
    title.setPosition(window_size.x / 2.f, 250);
    title.setScale(0.3, 0.3);

    setup_gui(window_size);
}

void MenuState::render()
{
    window.draw(background);

    if (is_current)
    {
        window.draw(title);
        window.draw(gui_container);
    }
}

bool MenuState::update()
{
    return true;
}

bool MenuState::handle_event(const sf::Event &event)
{
    gui_container.handle_event(event);

    return true;
}

void MenuState::setup_gui(sf::Vector2u window_size)
{
    static GUI_Builder builder;

    auto play = builder.set_text("PLAY")
            .set_position(window_size.x / 2.f, 550)
            .set_callback_1(nullptr)
            .make_button();

    builder.clear();

    auto settings = builder.set_text("SETTINGS")
            .set_position(window_size.x / 2.f, 650)
            .set_callback_1([this] () {request_stack_push(StateID::SETTINGS);})
            .make_button();

    builder.clear();

    auto high_scores = builder.set_text("HIGH SCORES")
            .set_position(window_size.x / 2.f, 750)
            .set_callback_1([this] () {
                request_stack_pop();
                request_stack_push(StateID::HIGH_SCORES);
            })
            .make_button();

    builder.clear();

        auto exit =  builder.set_text("EXIT")
            .set_position(window_size.x / 2.f, 850)
            .set_callback_1([this] () {window.close();})
            .make_button();

    builder.clear();

    gui_container.pack(play);
    gui_container.pack(settings);
    gui_container.pack(high_scores);
    gui_container.pack(exit);
    gui_container.select_first();
}
