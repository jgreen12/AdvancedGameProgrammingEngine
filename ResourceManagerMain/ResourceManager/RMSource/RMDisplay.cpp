#include "RMDisplay.h"

#include <memory>

namespace Display
{
    std::unique_ptr<sf::RenderWindow> window;

    void init()
    {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH,HEIGHT), "Window");
    }

    void clear()
    {
        window->clear();
    }

    void display()
    {
        window->display();
    }

    void draw(const sf::Drawable& drawable)
    {
        window->draw(drawable);
    }

    void checkWindowEvents()
    {
        sf::Event e;

        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window->close();
            }
        }
    }

    bool isOpen()
    {
        return window->isOpen();
    }
}
