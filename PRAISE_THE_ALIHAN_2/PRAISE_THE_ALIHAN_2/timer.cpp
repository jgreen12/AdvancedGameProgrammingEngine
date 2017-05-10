#include <iostream>
#include <ctime>
#include "Timer.h"
#include <windows.h>

//using std::list;


	Timer::Timer(){
		fps = 60;
		target = 1000 / fps;
		prev = target;
	}

	Timer::Timer(clock_t targetFPS) {
		fps = targetFPS;
		target = 1000/fps;
		prev = target;
	}

	clock_t Timer::deltaTime() {
		return clock() / (CLOCKS_PER_SEC / 1000) - prev;
	}

	void Timer::update() {
		if (target >= deltaTime())
			Sleep(target - deltaTime());
		else if (target < deltaTime())
			Sleep(deltaTime() - target);
		//std::cout << prev << std::endl;
		prev = clock();
	}
