#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    Game(uint32_t x, uint32_t y);
    void run(int fps);

private:
    void render();
    void update(sf::Time deltaTime);
    void processEvents();

    sf::RenderWindow window_;
};

#endif