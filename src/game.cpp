//
// Created by Gianni on 18/12/2023.
//

#include "../include/game.hpp"

Game::Game()
{
    Textures::load_directory("../assets/textures");

    window.create({500, 500}, "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
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
    sf::Event event{};

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
    }
}

void Game::update()
{

}

void Game::render()
{
    window.clear();

    window.display();
}
