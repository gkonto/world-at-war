#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include <SFML/Graphics.hpp>

namespace ui
{
    class Widget : public sf::Drawable
    {
    public:
        explicit Widget(Widget *parent);
        virtual ~Widget() = default;

        virtual sf::Vector2f size() const = 0;
        virtual void updateShape();

        void setPosition(float x, float y);
        const sf::Vector2f &position() const;
        void setParent(Widget *parent);
        Widget *parent() const;

    private:
        Widget *parent_ = nullptr; // FIXME who manages this item ?
        sf::Vector2f position_;
    };
}

#endif