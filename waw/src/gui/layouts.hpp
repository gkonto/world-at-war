#ifndef LAYOUTS_HPP_INCLUDED
#define LAYOUTS_HPP_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>

namespace ui
{
    class TextButton;

    class VLayout : public sf::Drawable
    {
    public:
        void add(TextButton *b);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::vector<TextButton *> widgets_;
    };
}

#endif