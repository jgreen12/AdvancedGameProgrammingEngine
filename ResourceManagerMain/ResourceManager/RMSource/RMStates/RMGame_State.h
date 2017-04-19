#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

#include "../Resource_Managers/Resource_Holder.h"

class Application;  //faster than #include "Application.h" at compile time

namespace State
{
    class Game_State
    {
        public:
            Game_State(Application& application);

            virtual void input  () = 0;
            virtual void update (float dt) = 0;
            virtual void draw   () = 0;

        protected:
            Application* m_p_application;
    };
}

#endif // GAME_STATE_H_INCLUDED
