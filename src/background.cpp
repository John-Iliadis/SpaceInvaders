//
// Created by Gianni on 2/01/2024.
//

#include "../include/background.hpp"

Background::Background(sf::Vector2u window_size)
    : window_size(window_size)
{
    auto& texture = Textures::get("game_background");
    texture.setRepeated(true);
    auto texture_dimensions = texture.getSize();
    sprite.setTexture(texture);
    sprite.setTextureRect({0, 0, (int)sprite.getGlobalBounds().width, (int)sprite.getGlobalBounds().height * 2});
    sprite.setScale((float)window_size.x / texture_dimensions.x, (float)window_size.y / texture_dimensions.y);
    sprite.setOrigin(0, sprite.getLocalBounds().height / 2);
}

void Background::update()
{
    auto pos = sprite.getPosition();

    if (pos.y >= window_size.y)
    {
        float offset = pos. y - window_size.y;
        sprite.setPosition(0, offset);
    }

    sprite.move(0, 2);
}

void Background::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}
