#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <array>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
enum class FontType
{
    Gui,
};

class FontResourceManager
{
public:
    static FontResourceManager &get();
    const tgui::Font &getFont(FontType type);

private:
    FontResourceManager();
    tgui::Font gui_;
};

#endif