#include "Font_Manager.h"

Font_Manager::Font_Manager() //This is where you add new font files. Easier if all placed in Res folder / Fonts folder
{							//Don't forget to head to the header file too.
	//example of new font file
	//addResource(Font_Name::fontExample, "Res/Fonts/Example.ttf");

    addResource(Font_Name::Test, "Res/Fonts/rs.ttf");
}
