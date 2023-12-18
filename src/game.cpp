//
// Created by Gianni on 18/12/2023.
//

#include "../include/game.hpp"

Game::Game()
    : state_stack(window)
{
    Textures::load_directory("../assets/textures");
    SoundBuffers::load_directory("../assets/audio");

    unsigned int width = Textures::get("menu_background").getSize().x / 2;
    unsigned int height = Textures::get("menu_background").getSize().y / 2;

    window.create({width, height}, "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    register_game_states();
    state_stack.push_state(StateID::MENU);
}

void Game::run()
{
    while (window.isOpen())
    {
        handle_events();
        update();
        render();
    }
}

void Game::handle_events()
{
    static sf::Event event{};

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
            if (event.key.code == sf::Keyboard::Escape)
                window.close();

        state_stack.handle_event(event);
    }
}

void Game::update()
{
    state_stack.update();
}

void Game::render()
{
    window.clear();
    state_stack.render();
    window.display();
}

void Game::register_game_states()
{
    state_stack.register_state<MenuState>(StateID::MENU);
}
