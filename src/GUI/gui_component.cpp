//
// Created by Gianni on 18/12/2023.
//

#include "../../include/GUI/gui_component.hpp"

GUI_Component::GUI_Component()
    : selected(false)
{
}

bool GUI_Component::is_selected() const
{
    return selected;
}

void GUI_Component::select()
{
    selected = true;
}

void GUI_Component::deselect()
{
    selected = false;
}

void GUI_Component::activate()
{
}
