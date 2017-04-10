#include "Sound_Manager.h"

Sound_Manager::Sound_Manager() //This is where you add new audio files. Easier if all placed in Res folder / Sounds folder
{								//Don't forget to head to the header file too.
	//example of new audio file
	//addResource(Sound_Name::audioExample, "Res/Sounds/Example.ogg");

    addResource(Sound_Name::Test, "Res/Sounds/Sound.ogg");
}
