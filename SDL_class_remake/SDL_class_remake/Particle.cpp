#include "Particle.h"
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <cmath>

namespace judg3
{

	Particle::Particle(): m_x(0), m_y(0)
	{
		/*m_x = 2.0 * ((double)rand() / RAND_MAX) - 1;
		m_y = 2.0 * ((double)rand() / RAND_MAX) - 1; */

		direction = (2 * M_PI * rand()) / RAND_MAX;
		mspeed = (0.008 * rand()) / RAND_MAX;
	}


	Particle::~Particle()
	{
	}

	void Particle::update()
	{

		m_x += mspeed * cos(direction);
		m_y += mspeed * sin(direction);

		if (m_x <= -1 || m_x >= 1)
		{
			direction = M_PI - direction;
		}

		if (m_y <= -1 || m_y >= 1)
		{
			direction = 2 * M_PI - direction;
		}
	}

}/*Namespace judg3*/