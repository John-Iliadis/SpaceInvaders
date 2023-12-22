//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_BUTTON_HPP
#define SPACEINVADERS_BUTTON_HPP

#include <functional>

#include <SFML/Graphics/Text.hpp>

#include "../utilities.hpp"
#include "gui_component.hpp"
#include "../asset_manager.hpp"

class Button : public GUI_Component
{
public:
    Button(const std::string& l_text,
           sf::Vector2f l_position,
           std::function<void()> l_callback);

    void set_text(const std::string& l_text);

    void select() override;
    void deselect() override;

    void activate() override;

    bool is_selectable() const override;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Text text;
    std::function<void()> callback;

    static constexpr int size_unselected = 128;
    static constexpr int size_selected = 148;
};


#endif //SPACEINVADERS_BUTTON_HPP
