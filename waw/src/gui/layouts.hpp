#ifndef LAYOUTS_HPP_INCLUDED
#define LAYOUTS_HPP_INCLUDED

#include <vector>

namespace ui
{
    class TextButton;

    class VLayout
    {
    public:
        void add(TextButton *b);

    private:
        std::vector<TextButton *> widgets_;
    };
}

#endif