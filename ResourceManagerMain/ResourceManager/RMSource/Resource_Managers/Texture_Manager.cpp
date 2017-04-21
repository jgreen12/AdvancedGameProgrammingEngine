#include "Texture_Manager.h"

Texture_Manager::Texture_Manager() //This is where you add new pictures or textures files. Easier if all placed in Res folder / Textures folder.
{									//Don't forget to add to header file too.
	//example of new texture file
	//addResource(Texture_Name::textureExample, "Res/Textures/Example.png");

    addResource(Texture_Name::Test, "Res/Textures/Face.png");
    addResource(Texture_Name::Slime, "Res/Textures/Slime.png");
}
