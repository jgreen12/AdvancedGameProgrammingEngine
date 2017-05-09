//From Matt Hopson's SFML Game Engine Tutorial
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#include "Font_Manager.h"

Font_Manager::Font_Manager() //This is where you add new font files. Easier if all placed in Res folder / Fonts folder
{							//Don't forget to head to the header file too.
	//example of new font file
	//addResource(Font_Name::fontExample, "Res/Fonts/Example.ttf");

    addResource(Font_Name::Test, "Res/Fonts/rs.ttf");
}

//        text.setString("Hello");			//Buffer
