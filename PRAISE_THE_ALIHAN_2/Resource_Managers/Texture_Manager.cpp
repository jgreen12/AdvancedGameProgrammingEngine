//From Matt Hopson's SFML Game Engine Tutorial
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#include "Texture_Manager.h"

Texture_Manager::Texture_Manager() //This is where you add new pictures or textures files. Easier if all placed in Res folder / Textures folder.
{									//Don't forget to add to header file too.
	//example of new texture file
	//addResource(Texture_Name::textureExample, "Res/Textures/Example.png");

    addResource(Texture_Name::Test, "Res/Textures/Face.png");
    addResource(Texture_Name::Slime, "Res/Textures/Slime.png");
}

//        shape.setTexture(&Resource_Holder::get().getTexture(Texture_Name::Slime));	//This is the buffer