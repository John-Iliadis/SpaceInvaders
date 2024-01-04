//
// Created by Gianni on 1/01/2024.
//

#include "../../include/entities/player.hpp"


Player::Player(sf::Vector2u window_size)
    : window_size(window_size)
    , lives(3)
    , score()
{
    sprite.setTexture(Textures::get("player"));
    sprite.scale(2, 2);
    sprite.setPosition(100, window_size.y - 120);

    ss = SpriteSheet(&sprite, {32, 32});
    animation = Animation(&ss, 100, true, true);

    velocity = {12, 0};
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void Player::update()
{
    animation.update();
}

void Player::move(float x, float y)
{
    sprite.move(x, y);

    if (get_rect().left < 0)
        set_position(0, get_position().y);
    else if (get_rect().left + get_rect().width > window_size.x)
        set_position(window_size.x - get_rect().width, get_position().y);
}

void Player::set_shooting_callback(std::function<void()> callback)
{
    shooting_callback = std::move(callback);
}

sf::Vector2f Player::get_shooting_pos() const
{
    auto pos = sprite.getPosition();
    auto bounds = sprite.getGlobalBounds();

    return {pos.x + bounds.width / 2.f, pos.y + 5};
}

int Player::get_lives() const
{
    return lives;
}

int Player::get_score() const
{
    return score;
}

void Player::shoot()
{
    shooting_callback();
}
