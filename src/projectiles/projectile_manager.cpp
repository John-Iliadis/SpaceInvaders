//
// Created by Gianni on 2/01/2024.
//

#include "../../include/projectiles/projectile_manager.hpp"


ProjectileManager::ProjectileManager(sf::Vector2u window_size)
    : window_size(window_size)
{
    projectile_factory[Projectile::Type::Player] = [] (sf::Vector2f pos) {return std::make_unique<PlayerProjectile>(pos);};
    projectile_factory[Projectile::Type::Alien] = [] (sf::Vector2f pos) {return std::make_unique<AlienProjectile>(pos);};
}
//
//void ProjectileManager::add_projectile(Projectile::Type type, sf::Vector2f pos)
//{
//    projectiles.push_back(std::move(projectile_factory[type](pos)));
////    switch (type)
////    {
////        case Projectile::Type::Player: // todo: check if you have to use move with push_back instead
////            projectiles.emplace_back(std::make_unique<PlayerProjectile>(pos));
////            break;
////        case Projectile::Type::Alien:
////            projectiles.emplace_back(std::make_unique<AlienProjectile>(pos));
////            break;
////    }
//}

void ProjectileManager::update()
{
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                     [this] (auto& projectile) {
        projectile->update();

        auto pos = projectile->get_position();
        return pos.y + 100 > window_size.y || pos.y < -100;
    }), projectiles.end());
}

void ProjectileManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto& projectile : projectiles)
    {
        target.draw(*projectile);
    }
}

void ProjectileManager::add_player_projectile(sf::Vector2f pos)
{
    if (std::any_of(projectiles.begin(), projectiles.end(),
                    [] (const std::unique_ptr<Projectile>& projectile) {
        return projectile->get_type() == Projectile::Type::Player;
    }))
    {
        return;
    }

    projectiles.emplace_back(std::make_unique<PlayerProjectile>(pos));
}

void ProjectileManager::add_alien_projectile(sf::Vector2f pos)
{
    projectiles.emplace_back(std::make_unique<AlienProjectile>(pos));
}

