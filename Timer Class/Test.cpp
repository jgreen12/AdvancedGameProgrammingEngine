#include <iostream>
#include <ctime>
#include "Timer.h"

int main() {
	Timer *Testing = new Timer();
	while (1) {
		Testing->update();
//		std::cout << clock()/(CLOCKS_PER_SEC/1000) << std::endl;
	}
}