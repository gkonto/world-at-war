#include "frame.hpp"
#include "layouts.hpp"

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
    printf("ui::Frame::draw\n");
}