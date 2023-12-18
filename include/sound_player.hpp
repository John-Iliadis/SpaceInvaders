//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_SOUND_PLAYER_HPP
#define SPACEINVADERS_SOUND_PLAYER_HPP

#include <list>

#include <SFML/Audio/Sound.hpp>

#include "asset_manager.hpp"



class SoundPlayer
{
public:
    static void play(const std::string& key);
    static void stop();

private:
    SoundPlayer() = default;

private:
    static std::list<sf::Sound> sounds;
};


#endif //SPACEINVADERS_SOUND_PLAYER_HPP
