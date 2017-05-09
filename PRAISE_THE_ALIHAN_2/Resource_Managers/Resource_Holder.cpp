//From Matt Hopson's SFML Game Engine Tutorial
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#include "Resource_Holder.h"

const Resource_Holder& Resource_Holder::get()
{
    static Resource_Holder holder;  //creates holder only once
    return holder;                  //will return every time function is called
}

const sf::Texture& Resource_Holder::getTexture(Texture_Name name) const
{
    return textures.get(name);
}

const sf::SoundBuffer& Resource_Holder::getSoundBuff(Sound_Name name) const
{
    return sounds.get(name);
}

const sf::Font& Resource_Holder::getFont(Font_Name name) const
{
    return fonts.get(name);
}
