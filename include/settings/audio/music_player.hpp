//
// Created by Gianni on 22/12/2023.
//

#ifndef SPACEINVADERS_MUSIC_PLAYER_HPP
#define SPACEINVADERS_MUSIC_PLAYER_HPP

#include <string>
#include <fstream>
#include <iomanip>

#include <SFML/Audio/Music.hpp>

#include "../../json.hpp"


class MusicPlayer
{
public:
    static void init();
    static void save();

    static void play();
    static void pause();
    static void stop();

    static void increase_volume();
    static void decrease_volume();
    static int get_volume();

private:
    MusicPlayer() = default;

private:
    static sf::Music music;
    static json config;
};


#endif //SPACEINVADERS_MUSIC_PLAYER_HPP
