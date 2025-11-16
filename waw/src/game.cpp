#include "game.hpp"
#include "level.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gui/buttons.hpp"
#include "gui/layouts.hpp"
#include <TGUI/TGUI.hpp>
#include "resources.hpp"

Game::Game(uint32_t x, uint32_t y)
    : window_(sf::VideoMode({x, y}), "World at War"), gui_(window_)
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
    auto layout = tgui::VerticalLayout::create({"30%", "30%"});
    layout->setOrigin(0.5f, 0.5f);
    layout->setPosition({"50%", "50%"});

    auto nameLbl = tgui::Label::create("World at War");
    auto name2Lbl = tgui::Label::create("Eisenbach Gap");
    nameLbl->setTextSize(40);
    name2Lbl->setTextSize(25);
    nameLbl->setHorizontalAlignment(tgui::HorizontalAlignment::Center);
    name2Lbl->setHorizontalAlignment(tgui::HorizontalAlignment::Center);

    // TGUI font that corresponds to FontType::Gui
    auto &gui_font = FontResourceManager::get().getFont(FontType::Gui);

    nameLbl->getRenderer()->setFont(gui_font);
    name2Lbl->getRenderer()->setFont(gui_font);
    nameLbl->getRenderer()->setTextColor(tgui::Color::Red);
    name2Lbl->getRenderer()->setTextColor(tgui::Color::Red);

    auto playBtn = tgui::Button::create("Play");
    auto exitBtn = tgui::Button::create("Exit");

    auto styleButton = [&](const tgui::Button::Ptr &btn)
    {
        auto r = btn->getRenderer();
        r->setFont(gui_font);                      // FontType::Gui equivalent
        r->setBackgroundColor({200, 60, 60});      // base red
        r->setBackgroundColorHover({230, 90, 90}); // lighter on hover
        r->setBackgroundColorDown({160, 40, 40});  // darker when pressed
        r->setBorderColor({146, 20, 19});          // outline red
        r->setTextColor(tgui::Color::Black);
        r->setBorders({3, 3, 3, 3});
    };

    styleButton(playBtn);
    styleButton(exitBtn);

    layout->add(nameLbl);
    layout->add(name2Lbl);
    layout->add(playBtn);
    layout->add(exitBtn);
    layout->getRenderer()->setSpaceBetweenWidgets(10.f);

    gui_.add(layout);

    exitBtn->onPress([this]
                     { window_.close(); });
}

void Game::render()
{
    window_.clear();
    gui_.draw();
    //  window_.draw(mainMenu_);
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