//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_WORLD_HPP
#define SPACEINVADERS_WORLD_HPP

#include <SFML/System/Clock.hpp>
#include "game_states/context.hpp"
#include "entities/player.hpp"
#include "background.hpp"
#include "projectiles/projectile_manager.hpp"

class World
{
public:
    World(Context& context);

    void render();
    void update();
    void handle_event(const sf::Event& event);

private:
    Context& context;
    Background background;
    ProjectileManager projectile_manager;
    Player player;
};


#endif //SPACEINVADERS_WORLD_HPP
