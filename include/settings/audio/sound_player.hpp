//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_SOUND_PLAYER_HPP
#define SPACEINVADERS_SOUND_PLAYER_HPP

#include <list>
#include <string>
#include <fstream>
#include <iomanip>

#include <SFML/Audio/Sound.hpp>

#include "../../asset_manager.hpp"
#include "../../json.hpp"


class SoundPlayer
{
public:
    static void init();
    static void save();

    static void play(const std::string& key);
    static void stop();

    static void increase_volume();
    static void decrease_volume();
    static void set_volume(int volume);
    static int get_volume();

private:
    SoundPlayer() = default;

private:
    static std::list<sf::Sound> sounds;
    static json config;
};


#endif //SPACEINVADERS_SOUND_PLAYER_HPP
