//
// Created by Gianni on 22/12/2023.
//

#ifndef SPACEINVADERS_GUI_BUILDER_HPP
#define SPACEINVADERS_GUI_BUILDER_HPP

#include <functional>
#include <memory>

#include <SFML/Graphics/Text.hpp>

class Button;
class Slider;
class Label;

class GUI_Builder
{
public:
    GUI_Builder() = default;

    void clear();

    GUI_Builder& set_text(const std::string& l_text);
    GUI_Builder& set_position(float x_pos, float y_pos);
    GUI_Builder& set_color(sf::Color l_color);
    GUI_Builder& set_callback_1(std::function<void()> l_callback_1);
    GUI_Builder& set_callback_2(std::function<void()> l_callback_2);
    GUI_Builder& set_font_size(int l_font_size);
    GUI_Builder& set_level(int l_level);

    std::shared_ptr<Button> make_button();
    std::shared_ptr<Label> make_label();
    std::shared_ptr<Slider> make_slider();

private:
    std::string text;
    sf::Color color;
    sf::Vector2f position;
    std::function<void()> callback_1;
    std::function<void()> callback_2;
    int font_size{};
    int level{};
};


#endif //SPACEINVADERS_GUI_BUILDER_HPP
