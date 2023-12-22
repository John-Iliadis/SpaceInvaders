//
// Created by Gianni on 21/12/2023.
//

#ifndef SPACEINVADERS_SLIDER_HPP
#define SPACEINVADERS_SLIDER_HPP

#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include "gui_component.hpp"
#include "../utilities.hpp"
#include "../asset_manager.hpp"

class Slider : public GUI_Component
{
public:
    Slider(const std::string& l_text,
           sf::Vector2f l_position,
           int l_level,
           std::function<void()> l_increment_callback,
           std::function<void()> l_decrement_callback);

    void select() override;
    void deselect() override;

    bool is_selectable() const override;
    void handle_event(const sf::Event& event) override;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setup_slider();
    void increment_level();
    void decrement_level();

private:
    sf::Text text;
    sf::RectangleShape slider;
    sf::RectangleShape level_bar;
    int level;
    bool show_slider;

    static constexpr int size_unselected = 128;
    static constexpr int size_selected = 148;
    static constexpr int offset = 400;

    std::function<void()> increment_callback;
    std::function<void()> decrement_callback;
};


#endif //SPACEINVADERS_SLIDER_HPP
