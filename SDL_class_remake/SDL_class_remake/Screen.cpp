#include "Screen.h"
#include <iostream>

namespace judg3
{

	Screen::Screen() :m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
	{

	}

	Screen::~Screen()
	{

	}

	bool Screen::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		m_window = SDL_CreateWindow("Goats Fire!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WITH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL)
		{
			SDL_Quit();
			return false;
		}


		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (m_renderer == NULL)
		{
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WITH, SCREEN_HEIGHT);

		if (m_texture == NULL)
		{
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer = new Uint32[SCREEN_WITH * SCREEN_HEIGHT];

		std::memset(m_buffer, 0, SCREEN_WITH * SCREEN_HEIGHT * sizeof(Uint32));

		SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WITH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

		return true;
	}

	bool Screen::processEvents()
	{
		SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					return false;
				}
			}

		return true;
	}

	void Screen::close()
	{
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();

	}

	void Screen::update()
	{
		SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WITH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		/*Setting 32 bit number to RGB mix by using bitshift*/
		Uint32 rgb = (red << 24) + (green << 16) + (blue << 8);
		/*Setting the buffer index to the RGB data*/
		m_buffer[x + (SCREEN_WITH * y)] = rgb;
	}

} /*Namespace Judg3*/