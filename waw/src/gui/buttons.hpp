#ifndef BUTTONS_HPP_INCLUDED
#define BUTTONS_HPP_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>
#include "widget.hpp"
#include "label.hpp"

namespace ui
{
    class TextButton : public Widget
    {
    public:
        explicit TextButton(Widget *parent, const char *text);
        void setSize(const sf::Vector2f &size);
        void setFillColor(const sf::Color &color);
        void setOutlineColor(const sf::Color &color);
        void setOutlineThickness(float thickness);

        void updateShape() override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        sf::Vector2f size() const override;

    private:
        Label label_;
        sf::RectangleShape shape_;
    };
}

#endif
