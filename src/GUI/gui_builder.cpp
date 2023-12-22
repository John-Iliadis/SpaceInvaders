//
// Created by Gianni on 22/12/2023.
//

#include "../../include/GUI/gui_builder.hpp"
#include "../../include/GUI/button.hpp"
#include "../../include/GUI/slider.hpp"
#include "../../include/GUI/label.hpp"


void GUI_Builder::clear()
{
    text = "";
    color = sf::Color();
    position = sf::Vector2f();
    callback_1 = nullptr;
    callback_2 = nullptr;
    font_size = 0;
    level = 0;
}

GUI_Builder& GUI_Builder::set_text(const std::string &l_text)
{
    text = l_text;

    return *this;
}

GUI_Builder& GUI_Builder::set_position(float x_pos, float y_pos)
{
    position = {x_pos, y_pos};

    return *this;
}

GUI_Builder& GUI_Builder::set_color(sf::Color l_color)
{
    color = l_color;

    return *this;
}

GUI_Builder& GUI_Builder::set_callback_1(std::function<void()> l_callback_1)
{
    callback_1 = std::move(l_callback_1);

    return *this;
}

GUI_Builder& GUI_Builder::set_callback_2(std::function<void()> l_callback_2)
{
    callback_2 = std::move(l_callback_2);

    return *this;
}

GUI_Builder& GUI_Builder::set_font_size(int l_font_size)
{
    font_size = l_font_size;

    return *this;
}

GUI_Builder& GUI_Builder::set_level(int l_level)
{
    level = l_level;

    return *this;
}

std::shared_ptr<Button> GUI_Builder::make_button()
{
//    if (text.empty() || callback_1 == nullptr)
//    {
//        throw std::runtime_error("GUI_Builder::make_button - Preperty not set\n");
//    }

    return std::make_shared<Button>(text, position, callback_1);
}

std::shared_ptr<Label> GUI_Builder::make_label()
{
//    if (text.empty() || font_size == 0)
//    {
//        throw std::runtime_error("GUI_Builder::make_label - Preperty not set\n");
//    }

    return std::make_shared<Label>(text, position, color, font_size);
}

std::shared_ptr<Slider> GUI_Builder::make_slider()
{
//    if (text.empty() || callback_1 == nullptr || callback_2 == nullptr)
//    {
//        throw std::runtime_error("GUI_Builder::make_slider - Preperty not set\n");
//    }

    return std::make_shared<Slider>(text, position, level, callback_1, callback_2);
}
