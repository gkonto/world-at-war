#include "widget.hpp"

ui::Widget::Widget(Widget *parent)
    : parent_(parent)
{
}

void ui::Widget::setPosition(float x, float y)
{
}

const sf::Vector2f &ui::Widget::position() const
{
    return position_;
}

void ui::Widget::setParent(Widget *parent)
{
    parent_ = parent;
}

ui::Widget *ui::Widget::parent() const
{
    return parent_;
}

void ui::Widget::updateShape()
{
    if (parent_)
    {
        parent_->updateShape();
    }
}