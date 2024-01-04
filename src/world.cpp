//
// Created by Gianni on 1/01/2024.
//

#include "../include/world.hpp"


World::World(Context& context)
    : context(context)
    , background(context.window->getSize())
    , projectile_manager(context.window->getSize())
    , player(context.window->getSize())
{
    context.player = &player;

    player.set_shooting_callback([this] () {
        projectile_manager.add_player_projectile(player.get_shooting_pos());
    });
}

void World::render()
{
    auto window = context.window;

    window->draw(background);
    window->draw(player);
    window->draw(projectile_manager);
}

void World::update()
{
    background.update();
    player.update();
    projectile_manager.update();
}

void World::handle_event(const sf::Event &event)
{
}
