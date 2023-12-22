//
// Created by Gianni on 18/12/2023.
//

#include "../../include/GUI/gui_container.hpp"

GUI_Container::GUI_Container()
    : children()
    , current_index()
{
}

void GUI_Container::pack(const std::shared_ptr<GUI_Component>& component)
{
    children.push_back(component);
}

bool GUI_Container::is_selectable() const
{
    return false;
}

void GUI_Container::handle_event(const sf::Event &event)
{
    children.at(current_index)->handle_event(event);

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
        {
            select_previous();
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
        {
            select_next();
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            children.at(current_index)->activate();
        }
    }
}

void GUI_Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (const auto& child : children)
    {
        target.draw(*child);
    }
}

void GUI_Container::select_previous()
{
    int prev = current_index;

    do
    {
        prev = (prev + children.size() - 1) % children.size();
    } while (!children.at(prev)->is_selectable());

    select(prev);
}

void GUI_Container::select_next()
{
    int next = current_index;

    do
    {
        next = (next + 1) % children.size();
    } while (!children.at(next)->is_selectable());

    select(next);
}

void GUI_Container::select(int index)
{
    if (children.at(index)->is_selectable())
    {
        children.at(current_index)->deselect();

        current_index = index;
        children.at(current_index)->select();
    }
}

void GUI_Container::select_first()
{
    if (children.at(current_index)->is_selectable())
        children.at(current_index)->deselect();

    for (this->current_index = 0; current_index < children.size(); ++current_index)
    {
        if (children.at(current_index)->is_selectable())
        {
            children.at(current_index)->select();
            return;
        }
    }
}
