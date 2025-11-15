#ifndef LAYOUTS_HPP_INCLUDED
#define LAYOUTS_HPP_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "widget.hpp"
#include <memory>

namespace ui
{
    class VLayout : public Widget
    {
    public:
        explicit VLayout(Widget *parent);

        sf::Vector2f size() const override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void add(std::unique_ptr<Widget> b);
        void setSpace(int pixels);

    private:
        void updateShape() override;
        std::vector<std::unique_ptr<Widget>> widgets_;
        int space_;
    };
}

#endif