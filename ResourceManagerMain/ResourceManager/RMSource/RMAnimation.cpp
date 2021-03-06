#include "RMAnimation.h"

void Animation::addFrame(const sf::IntRect& rect, float timeToNextFrame)
{
    m_frames.emplace_back(rect, timeToNextFrame);
}

sf::IntRect Animation::getFrame()
{
    if (m_timer.getElapsedTime().asSeconds() >=         //when elapsed time reaches
        m_frames.at(m_currentFrame).timeToNextFrame)    //the next frame
    {
        m_currentFrame++;
        m_timer.restart();

        if (m_currentFrame == m_frames.size())
        {
            m_currentFrame = 0;
        }
    }

    return m_frames.at(m_currentFrame).rect;
}
