//
// Created by Gianni on 21/12/2023.
//

#include "../../include/game_states/settings_state.hpp"

SettingsState::SettingsState(StateStack &state_stack, sf::RenderWindow &window)
    : State(state_stack, window)
{
    setup_gui(window.getSize());
}

void SettingsState::on_exit()
{
    KeyBindings::save();
    MusicPlayer::save();
    SoundPlayer::save();
}

void SettingsState::render()
{
    window.draw(gui_container);
}

bool SettingsState::update()
{
    return false;
}

bool SettingsState::handle_event(const sf::Event &event)
{
    gui_container.handle_event(event);
    return false;
}

void SettingsState::setup_gui(sf::Vector2u window_size)
{
    static GUI_Builder builder;

    auto settings = builder.set_text("Settings")
            .set_position(window_size.x / 2.f, 120)
            .set_color({200, 0, 0})
            .set_font_size(220)
            .make_label();

    builder.clear();

    auto audio = builder.set_text("Audio")
            .set_position(window_size.x / 2.f, 260)
            .set_color({100, 100, 100})
            .set_font_size(130)
            .make_label();

    builder.clear();

    auto music = builder.set_text("Music")
            .set_position(window_size.x / 2.f, 350)
            .set_level(MusicPlayer::get_volume())
            .set_callback_1([] () {MusicPlayer::increase_volume();})
            .set_callback_2([] () {MusicPlayer::decrease_volume();})
            .make_slider();

    builder.clear();

    auto sound = builder.set_text("Sound")
            .set_position(window_size.x / 2.f, 430)
            .set_level(SoundPlayer::get_volume())
            .set_callback_1([] () {SoundPlayer::increase_volume();})
            .set_callback_2([] () {SoundPlayer::decrease_volume();})
            .make_slider();

    builder.clear();

    auto key_bindings = builder.set_text("Key Bindings")
            .set_position(window_size.x / 2.f, 570)
            .set_color({100, 100, 100})
            .set_font_size(130)
            .make_label();

    builder.clear();

    auto move_left = builder.set_text("Move Left: [" + KeyBindings::get_move_left() + "]")
            .set_position(window_size.x / 2.f, 670)
            .set_callback_1([this] () {request_stack_pop();
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::LEFT);})
            .make_button();

    builder.clear();

    auto move_right = builder.set_text("Move Right: [" + KeyBindings::get_move_right() + "]")
            .set_position(window_size.x / 2.f, 770)
            .set_callback_1([this] () {request_stack_pop();
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::RIGHT);})
            .make_button();

    builder.clear();

    auto shoot = builder.set_text("Shoot: [" + KeyBindings::get_shoot() + "]")
            .set_position(window_size.x / 2.f, 870)
            .set_callback_1([this] () {request_stack_pop();
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::SHOOT);})
            .make_button();

    builder.clear();

    auto back = builder.set_text("Back")
            .set_position(window_size.x - 200, 920)
            .set_callback_1([this] () {request_stack_pop();})
            .make_button();

    builder.clear();

    gui_container.pack(settings);
    gui_container.pack(audio);
    gui_container.pack(music);
    gui_container.pack(sound);
    gui_container.pack(key_bindings);
    gui_container.pack(move_left);
    gui_container.pack(move_right);
    gui_container.pack(shoot);
    gui_container.pack(back);

    gui_container.select_first();
}
