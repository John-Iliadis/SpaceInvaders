//
// Created by Gianni on 1/01/2024.
//

#ifndef SPACEINVADERS_PLAYER_HPP
#define SPACEINVADERS_PLAYER_HPP

#include <functional>
#include "../projectiles/projectile.hpp"
#include "entity.hpp"
#include "movable_object.hpp"
#include "../animation/sprite_sheet.hpp"
#include "../animation/animation.hpp"
#include "../asset_manager.hpp"
#include "shooter.hpp"
#include "../utilities.hpp"


class Player : public Entity, public MovableObject, public Shooter
{
public:
    Player() = default;
    Player(sf::Vector2u window_size);

    void update() override;
    void move(float x, float y) override;

    void shoot();
    void set_shooting_callback(std::function<void()> callback);

    sf::Vector2f get_shooting_pos() const override;

    int get_lives() const;
    int get_score() const;

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::function<void()> shooting_callback;
    SpriteSheet ss;
    Animation animation;
    sf::Vector2i window_size;
    int lives;
    int score;
};


#endif //SPACEINVADERS_PLAYER_HPP
