#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <array>
#include <SFML/Graphics.hpp>

enum class FontType
{
    Gui,
};

class FontResourceManager
{
public:
    static FontResourceManager &get();
    const sf::Font &getFont(FontType type);

private:
    FontResourceManager();
    sf::Font gui_;
};

#endif