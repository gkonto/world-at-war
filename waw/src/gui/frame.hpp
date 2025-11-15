#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "widget.hpp"
#include "layouts.hpp"

namespace ui
{
    class VLayout;

    class Frame : public Widget
    {
    public:
        explicit Frame(sf::RenderWindow &w, Widget *parent);

        sf::Vector2f size() const override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void setLayout(std::unique_ptr<VLayout> l);
        VLayout *layout() const;

    private:
        sf::RenderWindow &window_;
        std::unique_ptr<VLayout> layout_;
    };
}

#endif