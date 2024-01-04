//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_ALIEN_PROJECTILE_HPP
#define SPACEINVADERS_ALIEN_PROJECTILE_HPP

#include "../animation/sprite_sheet.hpp"
#include "../animation/animation.hpp"
#include "projectile.hpp"


class AlienProjectile : public Projectile
{
public:
    AlienProjectile(sf::Vector2f pos);

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    SpriteSheet sprite_sheet;
    Animation animation;
};


#endif //SPACEINVADERS_ALIEN_PROJECTILE_HPP
