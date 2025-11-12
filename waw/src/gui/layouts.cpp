#include "layouts.hpp"
#include "buttons.hpp"

void ui::VLayout::add(TextButton *b)
{
    widgets_.emplace_back(b);
    // TODO reshapre the button here.
}

void ui::VLayout::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto *w : widgets_)
    {
        target.draw(*w, states);
    }
}