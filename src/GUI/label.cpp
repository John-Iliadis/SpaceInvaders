//
// Created by Gianni on 18/12/2023.
//

#include "../../include/GUI/label.hpp"
Label::Label(const std::string &l_text, sf::Vector2f l_position, sf::Color l_color, int l_font_size)
{
    text.setFont(Fonts::get("pixel_type"));
    text.setCharacterSize(l_font_size);
    text.setString(l_text);
    text.setPosition(l_position);
    text.setFillColor(l_color);
    center_text(text);
}

bool Label::is_selectable() const
{
    return false;
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(text, states);
}
