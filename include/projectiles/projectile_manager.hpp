//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_PROJECTILE_MANAGER_HPP
#define SPACEINVADERS_PROJECTILE_MANAGER_HPP

#include <unordered_map>
#include <functional>
#include <vector>
#include <memory>
#include "player_projectile.hpp"
#include "alien_projectile.hpp"


using ProjectileFactory = std::unordered_map<Projectile::Type, std::function<std::unique_ptr<Projectile>(sf::Vector2f pos)>>;

class ProjectileManager : public sf::Drawable
{
public:
    ProjectileManager(sf::Vector2u window_size);

    void add_player_projectile(sf::Vector2f pos);
    void add_alien_projectile(sf::Vector2f pos);
    //void add_projectile(Projectile::Type type, sf::Vector2f pos);

    void update();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    ProjectileFactory projectile_factory; // todo: delete this
    std::vector<std::unique_ptr<Projectile>> projectiles;
    sf::Vector2u window_size;
};


#endif //SPACEINVADERS_PROJECTILE_MANAGER_HPP
