//
// Created by Gianni on 2/01/2024.
//

#include "../../include/projectiles/player_projectile.hpp"

PlayerProjectile::PlayerProjectile(sf::Vector2f pos)
    : Projectile(Projectile::Type::Player, pos)
{
    velocity = {0, -20};
    sprite.setTexture(Textures::get("player_projectile"));
    sprite.setScale(.5, .5);
    center_sprite(sprite);
}

void PlayerProjectile::update()
{
    sprite.move(velocity);
}

void PlayerProjectile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}
