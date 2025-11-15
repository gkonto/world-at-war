#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <array>
#include <SFML/Graphics.hpp>

enum class FontTypes
{
    Gui,
};

class FontResourceManager
{
public:
    static FontResourceManager &get();

private:
    FontResourceManager();
    sf::Font gui_;
};

#endif