//
// Created by Gianni on 18/12/2023.
//

#include "../../include/GUI/button.hpp"

Button::Button(const std::string &l_text, sf::Vector2f l_position, std::function<void()> l_callback)
{
    text.setFont(Fonts::get("pixel_type"));
    text.setCharacterSize(size_unselected);
    text.setString(l_text);
    text.setPosition(l_position);
    center_text(text);

    callback = std::move(l_callback);
}

void Button::set_text(const std::string &l_text)
{
    text.setString(l_text);
    // maybe center again here
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(text, states);
}

bool Button::is_selectable() const
{
    return true;
}

void Button::select()
{
    GUI_Component::select();

    text.setCharacterSize(size_selected);
    text.setFillColor(sf::Color::Yellow);

    center_text(text);
}

void Button::deselect()
{
    GUI_Component::deselect();

    text.setCharacterSize(size_unselected);
    text.setFillColor(sf::Color::White);

    center_text(text);
}

void Button::activate()
{
    if (callback) callback();
}
