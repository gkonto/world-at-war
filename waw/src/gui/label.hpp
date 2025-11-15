#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include "widget.hpp"
#include <SFML/Graphics.hpp>
namespace ui
{
    class Label : public Widget
    {
    public:
        explicit Label(Widget *parent, const std::string &text);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        sf::Vector2f size() const override;

        void setText(const std::string &text);
        void setCharacterSize(uint32_t size);
        uint32_t characterSize() const;
        void setTextColor(const sf::Color &color);

    private:
        sf::Text text_;
    };
}

#endif