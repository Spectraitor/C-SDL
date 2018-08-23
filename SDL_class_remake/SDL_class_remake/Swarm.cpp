#include "Swarm.h"

namespace judg3
{

	Swarm::Swarm()
	{
		m_Particle_ptr = new Particle[NPARTICLES];
	}


	Swarm::~Swarm()
	{
		delete[] m_Particle_ptr;
	}

} /*Namespace judg3*/