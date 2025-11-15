#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "widget.hpp"

namespace ui
{
    class VLayout;

    class Frame : public Widget
    {
    public:
        explicit Frame(sf::RenderWindow &w, Widget *parent);
        virtual ~Frame() = default;

        sf::Vector2f size() const override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void setLayout(VLayout *l);
        VLayout *layout() const;

    private:
        sf::RenderWindow &window_;
        VLayout *layout_;
    };
}

#endif