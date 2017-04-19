#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "RMGame_State.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../RMAnimation.h"

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input  () override;
            void update (float dt) override;
            void draw   () override;

        private:
            sf::RectangleShape shape;
            sf::Sound sound;
            sf::Text text;

            Animation walkAnimation;
    };
}

#endif // PLAYING_H_INCLUDED
