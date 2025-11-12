#include "frame.hpp"
#include "layouts.hpp"

ui::Frame::Frame(sf::RenderWindow &window)
    : window_(window)
{
}

void ui::Frame::setLayout(VLayout *l)
{
    if (layout_)
    {
        delete layout_;
    }

    layout_ = l;
    // TODO update the shape of the layout here.
}

void ui::Frame::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (layout_)
    {
        target.draw(*layout_, states);
    }
}
