#include "Particle.h"
#include <stdlib.h>

namespace judg3
{

	Particle::Particle()
	{
		m_x = 2.0 * ((double)rand() / RAND_MAX) - 1;
		m_y = 2.0 * ((double)rand() / RAND_MAX) - 1;
	}


	Particle::~Particle()
	{
	}

}/*Namespace judg3*/