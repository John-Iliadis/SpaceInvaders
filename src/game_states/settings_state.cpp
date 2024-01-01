//
// Created by Gianni on 21/12/2023.
//

#include "../../include/game_states/settings_state.hpp"

SettingsState::SettingsState(StateStack &state_stack, Context context)
    : State(state_stack, context)
{
    setup_gui();
    gui_container.select_first();
}

void SettingsState::on_return()
{
    State::on_return();

    int index = gui_container.get_index();
    gui_container.clear();

    setup_gui();

    gui_container.select(index);
}

void SettingsState::render()
{
    is_current? context.window->draw(gui_container) : (void)0;
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

void SettingsState::setup_gui()
{
    static GUI_Builder builder;

    sf::Vector2u window_size = context.window->getSize();

    auto settings = builder.set_text("SETTINGS")
            .set_position(window_size.x / 2.f, 115)
            .set_color({200, 0, 0})
            .set_font_size(220)
            .make_label();

    builder.clear();

    auto audio = builder.set_text("AUDIO")
            .set_position(window_size.x / 2.f, 260)
            .set_color({100, 100, 100})
            .set_font_size(130)
            .make_label();

    builder.clear();

    auto music = builder.set_text("MUSIC")
            .set_position(window_size.x / 2.f, 360)
            .set_level(MusicPlayer::get_volume())
            .set_callback_1([] () {MusicPlayer::increase_volume();})
            .set_callback_2([] () {MusicPlayer::decrease_volume();})
            .make_slider();

    builder.clear();

    auto sound = builder.set_text("SOUND")
            .set_position(window_size.x / 2.f, 460)
            .set_level(SoundPlayer::get_volume())
            .set_callback_1([] () {SoundPlayer::increase_volume();})
            .set_callback_2([] () {SoundPlayer::decrease_volume();})
            .make_slider();

    builder.clear();

    auto key_bindings = builder.set_text("KEY BINDINGS")
            .set_position(window_size.x / 2.f, 580)
            .set_color({100, 100, 100})
            .set_font_size(130)
            .make_label();

    builder.clear();

    auto move_left = builder.set_text("MOVE LEFT: [" + KeyBindings::get_move_left_str() + "]")
            .set_position(window_size.x / 2.f, 680)
            .set_callback_1([this] () {
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::LEFT);})
            .make_button();

    builder.clear();

    auto move_right = builder.set_text("MOVE RIGHT: [" + KeyBindings::get_move_right_str() + "]")
            .set_position(window_size.x / 2.f, 780)
            .set_callback_1([this] () {
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::RIGHT);})
            .make_button();

    builder.clear();

    auto shoot = builder.set_text("SHOOT: [" + KeyBindings::get_shoot_str() + "]")
            .set_position(window_size.x / 2.f, 880)
            .set_callback_1([this] () {
                request_stack_push(StateID::KEY_BINDING_STATE);
                KeyBindings::set_key_binding_event(KeyBindings::SHOOT);})
            .make_button();

    builder.clear();

    auto back = builder.set_text("BACK")
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
}
