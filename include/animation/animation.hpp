//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_ANIMATION_HPP
#define SPACEINVADERS_ANIMATION_HPP

#include <SFML/System/Clock.hpp>
#include "sprite_sheet.hpp"

class Animation
{
public:
    Animation();
    Animation(SpriteSheet* sprite_sheet,float speed, bool is_repeated, bool playing);

    void play();
    void pause();
    void stop();

    void update();

    bool has_ended() const;

private:
    SpriteSheet* sprite_sheet;
    bool repeated;
    bool ended;
    bool playing;
    float animation_speed;
    sf::Clock clock;
};


#endif //SPACEINVADERS_ANIMATION_HPP
