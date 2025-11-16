#include "buttons.hpp"
#include <SFML/Graphics.hpp>

ui::TextButton::TextButton(Widget *parent, const char *text)
    : Widget(parent), label_(this, text)
{
    setFillColor(sf::Color(200, 60, 60));
    setOutlineThickness(5);
    setOutlineColor(sf::Color(146, 20, 19));
    setSize({200.f, 50.f});
}

void ui::TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform.translate(position());
    target.draw(shape_, states);
    target.draw(label_, states);
}

sf::Vector2f ui::TextButton::size() const
{
    sf::FloatRect rect = shape_.getGlobalBounds();
    return rect.size;
}

void ui::TextButton::setSize(const sf::Vector2f &size)
{
    shape_.setSize(size);
}

void ui::TextButton::setFillColor(const sf::Color &color)
{
    shape_.setFillColor(color);
}

void ui::TextButton::setOutlineColor(const sf::Color &color)
{
    shape_.setOutlineColor(color);
}

void ui::TextButton::setOutlineThickness(float thickness)
{
    shape_.setOutlineThickness(thickness);
}

void ui::TextButton::updateShape()
{
    sf::Vector2f label_size = label_.size();
    uint32_t char_size = label_.characterSize();

    shape_.setSize({char_size * 2 + label_size.x, char_size * 2.5f + label_size.y});
    label_.setPosition(char_size, char_size);

    Widget::updateShape();
}