//
// Created by Gianni on 21/12/2023.
//

#include "../../include/GUI/slider.hpp"

Slider::Slider(const std::string& l_text,
               sf::Vector2f l_position,
               int l_level,
               std::function<void()> l_increment_callback,
               std::function<void()> l_decrement_callback)
{
    text.setFont(Fonts::get("pixel_type"));
    text.setCharacterSize(size_unselected);
    text.setString(l_text);
    text.setPosition(l_position);
    center_text(text);

    increment_callback = std::move(l_increment_callback);
    decrement_callback = std::move(l_decrement_callback);

    level = std::clamp(l_level, 0, 100);
    show_slider = false;

    setup_slider();
}

void Slider::select()
{
    GUI_Component::select();

    text.setCharacterSize(size_selected);
    text.setFillColor(sf::Color::Yellow);

    center_text(text);

    show_slider = true;
}

void Slider::deselect()
{
    GUI_Component::deselect();

    text.setCharacterSize(size_unselected);
    text.setFillColor(sf::Color::White);

    center_text(text);

    show_slider = false;
}

bool Slider::is_selectable() const
{
    return true;
}

void Slider::handle_event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
        {
            decrement_level();
        }
        else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
        {
            increment_level();
        }
    }
}

void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(text, states);

    if (show_slider)
    {
        target.draw(slider, states);
        target.draw(level_bar, states);
    }
}

void Slider::setup_slider()
{
    // setup slider
    sf::Vector2f slider_size {200, 40};
    sf::Vector2f text_position = text.getPosition();
    sf::Color slider_color {0x28344cff};

    slider.setSize(slider_size);
    slider.setFillColor(slider_color);
    slider.setPosition(text_position.x + offset, text_position.y);
    center_shape(slider);

    // setup level_bar
    float level_bar_width = slider_size.x * 0.94f * level * 0.01;
    float level_bar_height = slider_size.y - 2 * 0.03f * slider_size.x;
    float level_bar_xpos = slider.getGlobalBounds().left + 0.03 * slider_size.x;
    float level_bar_ypos = slider.getGlobalBounds().top + 0.03 * slider_size.x;
    sf::Color level_bar_color {0x4084e4ff};

    level_bar.setFillColor(level_bar_color);
    level_bar.setSize({level_bar_width, level_bar_height});
    level_bar.setPosition(level_bar_xpos, level_bar_ypos);
}

void Slider::increment_level()
{
    if (level < 100)
    {
        level += 10;
        level_bar.setSize({slider.getSize().x * 0.94f * level * 0.01f, slider.getSize().y - 2 * 0.03f * slider.getSize().x});

        if (increment_callback) increment_callback();
    }
}

void Slider::decrement_level()
{
    if (level > 0)
    {
        level -= 10;
        level_bar.setSize({slider.getSize().x * 0.94f * level * 0.01f, slider.getSize().y - 2 * 0.03f * slider.getSize().x});

        if (decrement_callback) decrement_callback();
    }
}
