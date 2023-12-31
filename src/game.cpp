//
// Created by Gianni on 18/12/2023.
//

#include "../include/game.hpp"

Game::Game()
{
    Textures::load_directory("../assets/textures");
    SoundBuffers::load_directory("../assets/audio");
    Fonts::load_directory("../assets/fonts");

    KeyBindings::init();
    SoundPlayer::init();
    MusicPlayer::init();
    HighScores::init();

    unsigned int width = Textures::get("menu_background").getSize().x / 2;
    unsigned int height = Textures::get("menu_background").getSize().y / 2;

    window.create({width, height}, "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    state_stack.set_context({&window});

    register_game_states();
    state_stack.push_state(StateID::GAME);
}

void Game::run()
{
    while (window.isOpen())
    {
        handle_events();
        update();
        render();
    }

    KeyBindings::save();
    SoundPlayer::save();
    MusicPlayer::save();
    HighScores::save();
}

void Game::handle_events()
{
    static sf::Event event{};

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
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
    state_stack.register_state<SettingsState>(StateID::SETTINGS);
    state_stack.register_state<KeyBindingState>(StateID::KEY_BINDING_STATE);
    state_stack.register_state<HighScoresState>(StateID::HIGH_SCORES);
    state_stack.register_state<GameOverState>(StateID::GAME_OVER);
    state_stack.register_state<SubmitScoreState>(StateID::SUBMIT_SCORE);
    state_stack.register_state<GameState>(StateID::GAME);
    state_stack.register_state<PauseState>(StateID::PAUSE);
}
