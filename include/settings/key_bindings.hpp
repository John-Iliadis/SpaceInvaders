//
// Created by Gianni on 22/12/2023.
//

#ifndef SPACEINVADERS_KEY_BINDINGS_HPP
#define SPACEINVADERS_KEY_BINDINGS_HPP

#include <string>
#include <fstream>
#include <iomanip>

#include <SFML/Window/Keyboard.hpp>

#include "../json.hpp"
#include "../utilities.hpp"

class KeyBindings
{
public:
    enum Keys
    {
        LEFT,
        RIGHT,
        SHOOT,
        NONE
    };

public:
    static void init();
    static void save();

    static void set_key_binding_event(KeyBindings::Keys event);
    static void set_key(sf::Keyboard::Key key);

    static std::string get_move_left();
    static std::string get_move_right();
    static std::string get_shoot();

private:
    KeyBindings() = default;

private:
    static json config;
    static Keys key_binding_event;
};


#endif //SPACEINVADERS_KEY_BINDINGS_HPP
