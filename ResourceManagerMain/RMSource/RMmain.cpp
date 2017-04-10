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

    Application app;

    app.runMainLoop();

    return 0;
}
