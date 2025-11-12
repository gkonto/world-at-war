#include "buttons.hpp"
#include <SFML/Graphics.hpp>

ui::TextButton::TextButton(const char *text)
    : text_(text)
{
    // Default appearance; can be customized via setters
    shape_.setSize({200.f, 50.f});
    shape_.setFillColor(sf::Color(200, 60, 60));
    position_ = {0.f, 0.f};
}

void ui::TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform.translate(position_);
    target.draw(shape_, states);
}

void ui::TextButton::setPosition(const sf::Vector2f &pos)
{
    position_ = pos;
}

const sf::Vector2f &ui::TextButton::getPosition() const
{
    return position_;
}

void ui::TextButton::setSize(const sf::Vector2f &size)
{
    shape_.setSize(size);
}

void ui::TextButton::setFillColor(const sf::Color &color)
{
    shape_.setFillColor(color);
}
