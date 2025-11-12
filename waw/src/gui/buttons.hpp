#ifndef BUTTONS_HPP_INCLUDED
#define BUTTONS_HPP_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

namespace ui
{
    class TextButton : public sf::Drawable
    {
    public:
        explicit TextButton(const char *text);
        void setPosition(const sf::Vector2f &pos);
        const sf::Vector2f &getPosition() const;
        void setSize(const sf::Vector2f &size);
        void setFillColor(const sf::Color &color);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::string text_;
        sf::RectangleShape shape_;
        sf::Vector2f position_;
    };
}

#endif
