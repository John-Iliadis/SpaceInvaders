//
// Created by Gianni on 2/01/2024.
//

#include "../../include/projectiles/alien_projectile.hpp"


AlienProjectile::AlienProjectile(sf::Vector2f pos)
    : Projectile(Projectile::Type::Alien, pos)
{
    velocity = {0, 20};

    sprite_sheet = SpriteSheet(&sprite, {36, 64});
    animation = Animation(&sprite_sheet, 100, true, true);
}

void AlienProjectile::update()
{
    sprite.move(velocity);
    animation.update();
}

void AlienProjectile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}
