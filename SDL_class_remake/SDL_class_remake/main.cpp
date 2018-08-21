#include <iostream>
#include <SDL.h>
#include <Windows.h>
#include <math.h>
#include "Screen.h"
using namespace std;
using namespace judg3;

int main(int argc, char *argv[])
{

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initialising SDL." << endl;
	}


	while (true)
	{
		int elapsed = SDL_GetTicks();
		Uint8 red = (1 + sin(elapsed * 0.0004)) * 128;
		Uint8 green = (1 + sin(elapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(elapsed * 0.0006)) * 128;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y)
		{
			for (int x = 0; x < Screen::SCREEN_WITH; ++x)
			{
				screen.setPixel(x, y, red, green, blue);
			}
		}

		screen.update();

		if (screen.processEvents() == false)
		{
			cout << "Ending programm!" << endl;
			break;
		}
	}

	return 0;
}