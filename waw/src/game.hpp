#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "gui/frame.hpp"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
class Game
{
public:
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    Game(uint32_t x, uint32_t y);
    void run(int fps);
    bool load(const std::string &configpath);

private:
    void render();
    void update(sf::Time deltaTime);
    void processEvents();

    void initGui();
    void initMenu();

    // ui::Frame mainMenu_;

    sf::RenderWindow window_;
    tgui::Gui gui_;
    std::unique_ptr<Level> level_;
};

#endif