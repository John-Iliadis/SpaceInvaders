//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_GUI_COMPONENT_HPP
#define SPACEINVADERS_GUI_COMPONENT_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace sf { class Event;}


class GUI_Component : public sf::Drawable, public sf::Transformable
{
public:
    GUI_Component();
    virtual ~GUI_Component() = default;

    virtual bool is_selectable() const = 0;

    bool is_selected() const;

    virtual void select();
    virtual void deselect();

    virtual void activate();

    virtual void handle_event(const sf::Event& event) {};

private:
    bool selected;
};


#endif //SPACEINVADERS_GUI_COMPONENT_HPP
