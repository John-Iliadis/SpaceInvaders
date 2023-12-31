//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_ASSET_MANAGER_HPP
#define SPACEINVADERS_ASSET_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <filesystem>
#include <stdexcept>
#include <cassert>

namespace fs = std::filesystem;


template <typename asset_type>
class AssetManager
{
public:
    static asset_type& get(const std::string& key);

    static void load(const std::string& key, const std::string& file_name);
    static void load_directory(const std::string& dir);
    static void remove(const std::string& key);

private:
    AssetManager() = default;

    static asset_type& get_impl(const std::string& key);

    static void load_impl(const std::string& key, const std::string& file_name);
    static void load_directory_impl(const std::string& dir);
    static void remove_impl(const std::string& key);

private:
    static std::unordered_map<std::string, std::unique_ptr<asset_type>> map;
};


#include "asset_manager.inl"


#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

typedef AssetManager<sf::Texture> Textures;
typedef AssetManager<sf::Font> Fonts;
typedef AssetManager<sf::SoundBuffer> SoundBuffers;

#endif //SPACEINVADERS_ASSET_MANAGER_HPP
