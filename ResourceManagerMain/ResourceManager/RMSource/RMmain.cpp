#include "RMApplication.h"
#include <iostream>
//#include "Util/Random.h"

int main()
{
    /*Random::init();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Random::intInRange(0, 10) << std::endl;
    }*/

     /*Random::init();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Random::floatInRange(0, 10) << std::endl;
    }*/
	sf::Music music;

	if (!music.openFromFile("Res/Music/AerisPianoByTannerHelland.ogg"))
	{
		std::cout << "Error" << std::endl;
	}

	music.play();
    Application app;

    app.runMainLoop();
	music.stop();

    return 0;
}
