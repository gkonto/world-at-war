#ifndef BUTTONS_HPP_INCLUDED
#define BUTTONS_HPP_INCLUDED
#include <string>
namespace ui
{
    class TextButton
    {
    public:
        explicit TextButton(const char *text);

    private:
        std::string text_;
    };
}

#endif