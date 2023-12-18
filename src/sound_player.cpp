//
// Created by Gianni on 18/12/2023.
//

#include "../include/sound_player.hpp"

std::list<sf::Sound> SoundPlayer::sounds;

void SoundPlayer::play(const std::string &key)
{
    const sf::SoundBuffer& sound_buffer = SoundBuffers::get(key);

    sf::Sound sound(sound_buffer);

    sounds.push_back(std::move(sound));
    sounds.back().play();
    sounds.remove_if([] (const sf::Sound& sound) {
        return sound.getStatus() == sf::Sound::Stopped;
    });
}

void SoundPlayer::stop()
{
    sounds.clear();
}