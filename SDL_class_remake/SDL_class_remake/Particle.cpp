#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace judg3
{

	Particle::Particle()
	{
		/*m_x = 2.0 * ((double)rand() / RAND_MAX) - 1;
		m_y = 2.0 * ((double)rand() / RAND_MAX) - 1; */

		m_x = 0;
		m_y = 0;

		m_xspeed = 0.005 * sin(rand());
		m_yspeed = 0.005 * sin(rand());
	}


	Particle::~Particle()
	{
	}

	void Particle::update()
	{

		m_x += m_xspeed;
		m_y += m_yspeed;

		if (m_x <= -1 || m_x >= 1)
		{
			m_xspeed = -m_xspeed;
		}

		if (m_y <= -1 || m_y >= 1)
		{
			m_yspeed = -m_yspeed;
		}
	}

}/*Namespace judg3*/