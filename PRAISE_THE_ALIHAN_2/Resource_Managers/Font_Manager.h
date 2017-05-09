//From Matt Hopson's SFML Game Engine Tutorial
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#ifndef FONT_MANAGER_H_INCLUDED
#define FONT_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <map>

#include "Resource_Manager.h"

enum class Font_Name	//Add the name of the new font here and don't forget to head to the cpp file.
{
    Test,
};

class Font_Manager : public Resource_Manager<Font_Name, sf::Font>
{
    public:
        Font_Manager();
};

#endif // FONT_MANAGER_H_INCLUDED
