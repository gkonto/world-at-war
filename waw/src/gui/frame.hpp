#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

namespace ui
{
    class VLayout;
    class Frame : public sf::Drawable
    {
    public:
        explicit Frame(sf::RenderWindow &window);
        void setLayout(VLayout *l);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        sf::RenderWindow &window_;
        VLayout *layout_ = nullptr;
    };
}

#endif