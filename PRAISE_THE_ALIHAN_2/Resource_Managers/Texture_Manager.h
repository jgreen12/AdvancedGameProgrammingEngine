//From Matt Hopson's SFML Game Engine Tutorial
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#ifndef TEXTURE_MANAGER_H_INCLUDED
#define TEXTURE_MANAGER_H_INCLUDED

#include <map>
#include <SFML/Graphics.hpp>

#include "Resource_Manager.h"

enum class Texture_Name	//Add the name of the new texture here and don't forget to head to the cpp file.
{
    Test,
    Slime,
};

class Texture_Manager : public Resource_Manager<Texture_Name, sf::Texture>
{
    public:
        Texture_Manager();

};

#endif // TEXTURE_MANAGER_H_INCLUDED
