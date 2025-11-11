#include "layouts.hpp"
#include "buttons.hpp"
void ui::VLayout::add(TextButton *b)
{
    widgets_.emplace_back(b);
    // TODO reshapre the button here.
}