#include "game.hpp"
#include "level.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gui/buttons.hpp"
#include "gui/layouts.hpp"

Game::Game(uint32_t x, uint32_t y)
    : window_(sf::VideoMode({x, y}), "World at War"), mainMenu_(window_, nullptr)

{
    initGui();
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
        render();
    }
}

void Game::initGui()
{
    initMenu();
}

void Game::initMenu()
{
    auto layout = std::make_unique<ui::VLayout>(nullptr);
    layout->setSpace(25);
    auto name_lbl = std::make_unique<ui::Label>(nullptr, "World at War");
    auto name2_lbl = std::make_unique<ui::Label>(nullptr, "Eisenbach Gap");

    name_lbl->setCharacterSize(40);
    name2_lbl->setCharacterSize(25);

    name_lbl->setTextColor(sf::Color::Red);
    name2_lbl->setTextColor(sf::Color::Red);

    auto play_btn = std::make_unique<ui::TextButton>(nullptr, "Play");
    auto exit_btn = std::make_unique<ui::TextButton>(nullptr, "Exit"); // TODO who manages this item ?
    layout->add(std::move(name_lbl));
    layout->add(std::move(name2_lbl));
    layout->add(std::move(play_btn));
    layout->add(std::move(exit_btn));
    mainMenu_.setLayout(std::move(layout));
}

void Game::render()
{
    window_.clear();
    window_.draw(mainMenu_);
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

bool Game::load(const std::string &configpath)
{
    bool res = true;
    level_ = std::make_unique<Level>(window_, configpath);
    return res;
}