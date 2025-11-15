#include "label.hpp"
#include "../resources.hpp"

ui::Label::Label(Widget *parent, const std::string &text)
    : Widget(parent), text_(FontResourceManager::get().getFont(FontType::Gui), text)
{
    setTextColor(sf::Color::Black);
}

void ui::Label::setText(const std::string &text)
{
    text_.setString(text);
}

void ui::Label::setCharacterSize(uint32_t size)
{
    text_.setCharacterSize(size);
    updateShape();
}

uint32_t ui::Label::characterSize() const
{
    return text_.getCharacterSize();
}

void ui::Label::setTextColor(const sf::Color &color)
{
    text_.setFillColor(color);
}

sf::Vector2f ui::Label::size() const
{
    auto rect = text_.getGlobalBounds();
    return rect.size;
}

void ui::Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform.translate(position());
    target.draw(text_, states);
}
