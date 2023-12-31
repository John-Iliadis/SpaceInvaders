//
// Created by Gianni on 21/12/2023.
//

#ifndef SPACEINVADERS_SETTINGS_STATE_HPP
#define SPACEINVADERS_SETTINGS_STATE_HPP

#include <memory>

#include "state.hpp"
#include "../GUI/gui_includes.hpp"
#include "../settings/key_bindings.hpp"
#include "../settings/audio/music_player.hpp"
#include "../settings/audio/sound_player.hpp"


class SettingsState : public State
{
public:
    SettingsState(StateStack& state_stack, sf::RenderWindow& window);

    void on_return() override;
    void render() override;
    bool update() override;
    bool handle_event(const sf::Event& event) override;

private:
    void setup_gui();

private:
    GUI_Container gui_container;
};


#endif //SPACEINVADERS_SETTINGS_STATE_HPP
