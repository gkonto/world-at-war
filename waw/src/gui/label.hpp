#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include "widget.hpp"
#include <SFML/Graphics.hpp>
namespace ui
{
    class Label : public Widget
    {
    public:
        explicit Label(Widget *parent);
        void setText(const std::string &text);

    private:
        // sf::Text text_;
    };
}

#endif