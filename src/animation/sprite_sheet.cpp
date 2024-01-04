//
// Created by Gianni on 1/01/2024.
//

#include "../../include/animation/sprite_sheet.hpp"


SpriteSheet::SpriteSheet()
    : sprite_sheet()
    , total_frames()
    , current_frame()
    , row()
{
}

SpriteSheet::SpriteSheet(sf::Sprite *sprite_sheet, sf::Vector2i size, int row /* = 0*/)
    : sprite_sheet(sprite_sheet)
    , size(size)
    , row(row)
    , current_frame()
{
    sprite_sheet->setTextureRect({0, row * size.y, size.x, size.y});
    total_frames = sprite_sheet->getTexture()->getSize().x / size.x;
}

void SpriteSheet::set_next()
{
    if (current_frame == total_frames - 1)
    {
        current_frame = 0;
        sprite_sheet->setTextureRect({0, row * size.y, size.x, size.y});
    }
    else
    {
        current_frame++;
        sprite_sheet->setTextureRect({current_frame * size.x, row * size.y, size.x, size.y});
    }
}

void SpriteSheet::set_start()
{
    current_frame = 0;
    sprite_sheet->setTextureRect({0, row * size.y, size.x, size.y});
}
