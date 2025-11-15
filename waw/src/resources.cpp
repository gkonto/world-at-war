#include "resources.hpp"
#include "utils.hpp"

FontResourceManager &FontResourceManager::get()
{
    static FontResourceManager instance;
    return instance;
}

FontResourceManager::FontResourceManager()
    : gui_(getAssetPath("font/trs-million.ttf"))
{
}

const sf::Font &FontResourceManager::getFont(FontType type)
{
    switch (type)
    {
    case FontType::Gui:
        return gui_;
    }
}
