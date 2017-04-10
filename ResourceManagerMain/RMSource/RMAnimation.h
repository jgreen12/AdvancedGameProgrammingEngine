#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    struct Frame
    {
        Frame(const sf::IntRect& rect, float timeToNextFrame)
        :   rect            (rect)
        ,   timeToNextFrame (timeToNextFrame)
        { }

        const sf::IntRect rect;
        const float timeToNextFrame;
    };

    public:
        void addFrame(const sf::IntRect& rect, float timeToNextFrame);

        sf::IntRect getFrame();

    private:
        std::vector<Frame> m_frames;

        sf::Clock m_timer;

        int m_currentFrame = 0;
};
#endif // ANIMATION_H_INCLUDED
