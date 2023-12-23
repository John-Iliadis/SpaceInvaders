//
// Created by Gianni on 18/12/2023.
//

#include "../../../include/settings/audio/sound_player.hpp"

std::list<sf::Sound> SoundPlayer::sounds;
json SoundPlayer::config;

void SoundPlayer::init()
{
    std::ifstream input_settings_file("../data/sound.json");

    if (!input_settings_file.is_open())
        throw std::runtime_error("SoundPlayer::init - Failed to load settings file");

    config = json::parse(input_settings_file);

    input_settings_file.close();
}

void SoundPlayer::save()
{
    std::ofstream output_settings_file("../data/sound.json", std::ios::trunc);

    if (!output_settings_file.is_open())
        throw std::runtime_error("SoundPlayer::init - Failed to load settings file");

    output_settings_file << std::setw(4) << config;

    output_settings_file.close();
}

void SoundPlayer::play(const std::string &key)
{
    const sf::SoundBuffer& sound_buffer = SoundBuffers::get(key);

    sf::Sound sound(sound_buffer);
    sound.setVolume(config["sound_volume"]);

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

void SoundPlayer::set_volume(int volume)
{
    int l_volume = std::clamp(volume, 0, 100);
    config["sound_volume"] = l_volume;
}

void SoundPlayer::increase_volume()
{
    set_volume(config["sound_volume"].get<int>() + 10);
}

void SoundPlayer::decrease_volume()
{
    set_volume(config["sound_volume"].get<int>() - 10);
}

int SoundPlayer::get_volume()
{
    return config["sound_volume"];
}
