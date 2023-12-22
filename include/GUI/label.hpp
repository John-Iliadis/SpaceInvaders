//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_LABEL_HPP
#define SPACEINVADERS_LABEL_HPP

#include <SFML/Graphics/Text.hpp>

#include "gui_component.hpp"
#include "../asset_manager.hpp"
#include "../utilities.hpp"

class Label : public GUI_Component
{
public:
    Label(const std::string& l_text,
          sf::Vector2f l_position,
          sf::Color l_color,
          int l_font_size);

    bool is_selectable() const override;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Text text;
};


#endif //SPACEINVADERS_LABEL_HPP
