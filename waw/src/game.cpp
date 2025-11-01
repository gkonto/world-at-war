#include "game.hpp"

#include <SFML/Graphics.hpp>

Game::Game(uint32_t x, uint32_t y)
    : window_(sf::VideoMode({x, y}), "World at War")
{
}

void Game::run(int fps)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame = sf::seconds(1.f / fps);

    while (window_.isOpen())
    {
        processEvents();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
        }
    }
}

void Game::render()
{
    window_.clear();
    window_.display();
}

void Game::update(sf::Time deltaTime)
{
}

void Game::processEvents()
{
    while (auto eventOpt = window_.pollEvent())
    {
        const auto &event = eventOpt.value();
        if (event.is<sf::Event::Closed>())
        {
            window_.close();
        }
        else if (event.is<sf::Event::KeyPressed>())
        {
            const auto *key = event.getIf<sf::Event::KeyPressed>();
            if (key->code == sf::Keyboard::Key::Escape)
            {
                window_.close();
            }
        }
    }
}