#include "RMPlaying_State.h"

#include "../RMApplication.h"
#include "../RMDisplay.h"
#include <iostream>

namespace State
{
    Playing::Playing(Application& application)
    :   Game_State (application)
    {
        shape.setSize({500,500});
        text.setString("Hello");

        shape.setTexture(&Resource_Holder::get().getTexture(Texture_Name::Slime));

        sound.setBuffer(Resource_Holder::get().getSoundBuff(Sound_Name::Test)); //*warning* bit loud
        text.setFont(Resource_Holder::get().getFont(Font_Name::Test));

        sound.play();

        walkAnimation.addFrame({0, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({50, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({100, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({150, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({200, 0, 50, 50}, 0.1);

        walkAnimation.addFrame({150, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({100, 0, 50, 50}, 0.1);
        walkAnimation.addFrame({50, 0, 50, 50}, 0.1);

    }

    void Playing::input()
    {

    }

    void Playing::update(float dt)
    {
        shape.setTextureRect(walkAnimation.getFrame());
    }

    void Playing::draw()
    {
        Display::draw(shape);
        Display::draw(text);
    }
}
