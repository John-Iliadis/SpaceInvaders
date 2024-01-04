//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_PLAYER_PROJECTILE_HPP
#define SPACEINVADERS_PLAYER_PROJECTILE_HPP

#include "projectile.hpp"
#include "../asset_manager.hpp"
#include "../utilities.hpp"

class PlayerProjectile : public Projectile
{
public:
    PlayerProjectile(sf::Vector2f pos);

    void update() override;

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SPACEINVADERS_PLAYER_PROJECTILE_HPP
