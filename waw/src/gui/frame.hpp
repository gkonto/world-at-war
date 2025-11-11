#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class VLayout;

namespace ui
{
    class VLayout;
    class Frame : public sf::Drawable
    {
    public:
        void setLayout(VLayout *l);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        VLayout *layout_ = nullptr;
    };
}

#endif