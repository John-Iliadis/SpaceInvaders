//
// Created by Gianni on 2/01/2024.
//

#ifndef SPACEINVADERS_BACKGROUND_HPP
#define SPACEINVADERS_BACKGROUND_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "asset_manager.hpp"

class Background : public sf::Drawable
{
public:
    Background(sf::Vector2u window_size);
    void update();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Sprite sprite;
    sf::Vector2u window_size;
};


#endif //SPACEINVADERS_BACKGROUND_HPP
