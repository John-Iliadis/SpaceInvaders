//
// Created by Gianni on 1/01/2024.
//

#include "../../include/animation/animation.hpp"

Animation::Animation()
    : sprite_sheet()
    , repeated(false)
    , ended(false)
    , playing(false)
    , animation_speed()
{
}

Animation::Animation(SpriteSheet *sprite_sheet, float speed, bool is_repeated, bool playing)
    : sprite_sheet(sprite_sheet)
    , repeated(is_repeated)
    , ended(false)
    , playing(playing)
    , animation_speed(speed)
{
}

void Animation::play()
{
    playing = true;
    clock.restart();
}

void Animation::pause()
{
    playing = false;
}

void Animation::stop()
{
    playing = false;
    sprite_sheet->set_start();
}

void Animation::update()
{
    if (!playing) return;

    if (!repeated)
    {
        if (sprite_sheet->current_frame == sprite_sheet->total_frames - 1)
        {
            ended = true;
            playing = false;
            return;
        }
    }

    if (clock.getElapsedTime().asMilliseconds() >= animation_speed)
    {
        sprite_sheet->set_next();
        clock.restart();
    }
}

bool Animation::has_ended() const
{
    return ended;
}
