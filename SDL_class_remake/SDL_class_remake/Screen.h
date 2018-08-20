#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>

namespace judg3
{
	class Screen
	{
	public:
		static const int SCREEN_WITH = 800;
		static const int SCREEN_HEIGHT = 600;

	private:
		SDL_Window * m_window; /*Window used by SDL*/
		SDL_Renderer *m_renderer; /*Renderer used by SDL*/
		SDL_Texture *m_texture; /*Texture used for pixel acces*/
		Uint32 *m_buffer; /*Array mapped to every pixel 4 bytes RGBA*/

	public:
		Screen();
		~Screen();
		bool init();
		bool processEvents();
		void close();
	};
}

#endif