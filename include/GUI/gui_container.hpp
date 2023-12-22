//
// Created by Gianni on 18/12/2023.
//

#ifndef SPACEINVADERS_GUI_CONTAINER_HPP
#define SPACEINVADERS_GUI_CONTAINER_HPP

#include <vector>
#include <memory>

#include <SFML/Window/Event.hpp>

#include "gui_component.hpp"

class GUI_Container : public GUI_Component
{
public:
    GUI_Container();

    void pack(const std::shared_ptr<GUI_Component>& component);

    bool is_selectable() const override;
    void handle_event(const sf::Event &event) override;

    void select(int index);
    void select_first();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void select_previous();
    void select_next();

private:
    std::vector<std::shared_ptr<GUI_Component>> children;
    int current_index;
};


#endif //SPACEINVADERS_GUI_CONTAINER_HPP
