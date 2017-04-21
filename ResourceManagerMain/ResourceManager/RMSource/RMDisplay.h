#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Display
{
    void init();

    void clear();
    void display();

    void checkWindowEvents();

    void draw(const sf::Drawable& drawable);

    bool isOpen();

    constexpr static int WIDTH      = 1280;
    constexpr static int HEIGHT     = 720;
}


#endif // DISPLAY_H_INCLUDED
