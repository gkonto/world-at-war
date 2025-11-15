#include "frame.hpp"
#include "layouts.hpp"
#include "widget.hpp"
#include <SFML/Graphics.hpp>

ui::Frame::Frame(sf::RenderWindow &w, Widget *parent)
    : Widget(parent), window_(w)
{
}

void ui::Frame::setLayout(VLayout *layout)
{
    layout_ = layout;
}

ui::VLayout *ui::Frame::layout() const
{
    return layout_;
}

void ui::Frame::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (layout_)
    {
        target.draw(*layout_, states);
    }
}

sf::Vector2f ui::Frame::size() const
{
    auto s = window_.getSize();
    return sf::Vector2f({static_cast<float>(s.x), static_cast<float>(s.y)});
}