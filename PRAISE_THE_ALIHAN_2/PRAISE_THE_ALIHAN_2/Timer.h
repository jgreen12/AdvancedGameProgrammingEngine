#include <iostream>
#include <ctime>
//create Timer object before beginning of infinte loop, place Timer->update at the very end of the loop


class Timer {
private:
	int fps;
	int target;
	int prev;

	Timer();

	Timer(clock_t targetFPS);

	clock_t deltaTime();

public:
	void update(); //calls a sleep function to ensure consistent frame rate
};