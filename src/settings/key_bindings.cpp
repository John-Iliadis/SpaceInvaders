//
// Created by Gianni on 22/12/2023.
//

#include "../../include/settings/key_bindings.hpp"


json KeyBindings::config;
KeyBindings::Keys KeyBindings::key_binding_event = NONE;

void KeyBindings::init()
{
    std::ifstream input_settings_file("../data/settings.json");

    if (!input_settings_file.is_open())
        throw std::runtime_error("KeyBindings::init - Failed to load settings file");

    config = json::parse(input_settings_file);

    input_settings_file.close();
}

void KeyBindings::save()
{
    std::ofstream output_settings_file("../data/settings.json", std::ios::trunc);

    if (!output_settings_file.is_open())
        throw std::runtime_error("KeyBindings::save - Failed to load settings file");

    output_settings_file << std::setw(4) << config;

    output_settings_file.close();
}

void KeyBindings::set_key_binding_event(KeyBindings::Keys event)
{
    key_binding_event = event;
}

std::string KeyBindings::get_move_left()
{
    return key_to_string(config["move_left"]);
}

std::string KeyBindings::get_move_right()
{
    return key_to_string(config["move_right"]);
}

std::string KeyBindings::get_shoot()
{
    return key_to_string(config["shoot"]);
}

void KeyBindings::set_key(sf::Keyboard::Key key)
{
    switch (key_binding_event)
    {
        case LEFT:
            config["move_left"] = key;
            break;

        case RIGHT:
            config["move_right"] = key;
            break;

        case SHOOT:
            config["shoot"] = key;
            break;

        case NONE:
            throw std::runtime_error("KeyBindings::set_key - key binding event is set to NONE");
            break;
    }
}
