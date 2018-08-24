#include <iostream>
#include <SDL.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Screen.h"
using namespace std;
using namespace judg3;

int main(int argc, char *argv[])
{
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	while (true)
	{
		int elapsed = SDL_GetTicks();
		Uint8 red = (1 + sin(elapsed * 0.0004)) * 128;
		Uint8 green = (1 + sin(elapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(elapsed * 0.0006)) * 128;

		swarm.update();

		/*for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y)
		{
			for (int x = 0; x < Screen::SCREEN_WITH; ++x)
			{
				screen.setPixel(x, y, 255 - red, 255 - green, 255 - blue);
			}
		}*/

		screen.clear();

		for (int i = 0; i < swarm.NPARTICLES; ++i)
		{
			screen.setPixel((swarm.getParticles()[i].m_x + 1) * (Screen::SCREEN_WITH / 2) , (swarm.getParticles()[i].m_y + 1) * (Screen::SCREEN_HEIGHT / 2), red, green, blue);
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