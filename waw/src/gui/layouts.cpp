#include "layouts.hpp"
#include "buttons.hpp"

ui::VLayout::VLayout(Widget *parent)
    : Widget(parent)
{
}

void ui::VLayout::add(std::unique_ptr<Widget> b)
{
    b->setParent(this);
    widgets_.emplace_back(std::move(b));
    updateShape();
}

void ui::VLayout::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &w : widgets_)
    {
        target.draw(*w.get(), states);
    }
}

sf::Vector2f ui::VLayout::size() const
{
    float max_x = 0;
    float y = 0;
    for (auto &w : widgets_)
    {
        auto s = w->size();
        max_x = std::max(max_x, s.x);
        y += space_ + s.y;
    }
    return sf::Vector2f({max_x + space_ * 2, y + space_});
}

void ui::VLayout::setSpace(int pixels)
{
    space_ = pixels;
    updateShape();
}

void ui::VLayout::updateShape()
{
    auto max_x = parent() ? parent()->size().x : 0;
    for (auto &w : widgets_)
    {
        auto size = w->size();
        max_x = std::max(max_x, size.x);
    }

    float pos_y = parent() ? parent()->size().y - size().y / 2.f : space_;

    for (auto &w : widgets_)
    {
        auto size = w->size();
        w->setPosition(max_x - size.x / 2., pos_y);
        pos_y += size.y + space_;
    }
    Widget::updateShape();
}