#include <iostream>
#include <SDL.h>
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
		if (screen.processEvents() == false)
		{
			cout << "Ending programm!" << endl;
			break;
		}
	}

	return 0;
}