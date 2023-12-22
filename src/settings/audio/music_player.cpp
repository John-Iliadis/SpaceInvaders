//
// Created by Gianni on 22/12/2023.
//

#include "../../../include/settings/audio/music_player.hpp"


sf::Music MusicPlayer::music;
json MusicPlayer::config;

void MusicPlayer::init()
{
    std::ifstream input_settings_file("../data/settings.json");

    if (!input_settings_file.is_open())
        throw std::runtime_error("MusicPlayer::init - Failed to load settings file");

    config = json::parse(input_settings_file);

    input_settings_file.close();

    music.openFromFile("../assets/audio/music/song.ogg");
    music.setVolume(config["music_volume"].get<int>());
    music.setLoop(true);
}

void MusicPlayer::save()
{
    std::ofstream output_settings_file("../data/settings.json", std::ios::trunc);

    if (!output_settings_file.is_open())
        throw std::runtime_error("MusicPlayer::save - Failed to load settings file");

    output_settings_file << std::setw(4) << config;

    output_settings_file.close();
}

void MusicPlayer::play()
{
    music.play();
}

void MusicPlayer::pause()
{
    music.pause();
}

void MusicPlayer::stop()
{
    music.stop();
}

void MusicPlayer::increase_volume()
{
    int volume = std::clamp(config["music_volume"].get<int>() + 10, 0, 100);
    music.setVolume(volume);
    config["music_volume"] = volume;
}

void MusicPlayer::decrease_volume()
{
    int volume = std::clamp(config["music_volume"].get<int>() - 10, 0, 100);
    music.setVolume(volume);
    config["music_volume"] = volume;
}

int MusicPlayer::get_volume()
{
    return config["music_volume"];
}

