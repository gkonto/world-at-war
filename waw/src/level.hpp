#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>

// Represents the map
class Level
{
public:
    Level(sf::RenderWindow &window, const std::string &filename);

private:
};

#endif