//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_UTILITIES_HPP
#define SPACEINVADERS_UTILITIES_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>

void center_text(sf::Text& text);
void set_text_origin_right(sf::Text& text);
void set_text_origin_left(sf::Text& text);
void center_shape(sf::Shape& shape);
void center_sprite(sf::Sprite& sprite);

std::string key_to_string(sf::Keyboard::Key key);

#endif //SPACEINVADERS_UTILITIES_HPP
