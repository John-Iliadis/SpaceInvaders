//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_SPRITE_SHEET_HPP
#define SPACEINVADERS_SPRITE_SHEET_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class SpriteSheet
{
    friend class Animation;
public:
    SpriteSheet();
    SpriteSheet(sf::Sprite* sprite_sheet, sf::Vector2i size, int row = 0);

    void set_next();
    void set_start();

private:
    sf::Sprite* sprite_sheet;
    sf::Vector2i size;
    int total_frames;
    int current_frame;
    int row;
};


#endif //SPACEINVADERS_SPRITE_SHEET_HPP
