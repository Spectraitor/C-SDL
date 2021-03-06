#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include <Windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	const int SCREEN_WITH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL init failed!" << endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Goats Fire!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WITH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Quit();
		cout << "Error opening window. Message:" << SDL_GetError() << endl;
		return 2;
	}

	cout << "Init succeded!" << endl;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "Could not create renderer." << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WITH, SCREEN_HEIGHT);

	if (texture == NULL)
	{
		cout << "Could not create texture." << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WITH * SCREEN_HEIGHT];

	memset(buffer, 0, SCREEN_WITH * SCREEN_HEIGHT * sizeof(Uint32));
	//memset(buffer + (10 * SCREEN_WITH), 0, SCREEN_WITH * 10 * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WITH * SCREEN_HEIGHT; ++i)
	{
		buffer[i] = 0xa423db00;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WITH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

		bool quit = false;

	SDL_Event event;

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	//Sleep(5000);

	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}