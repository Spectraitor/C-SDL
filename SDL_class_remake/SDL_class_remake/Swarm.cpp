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

	void Swarm::update()
	{
		for (int i = 0; i < NPARTICLES; ++i)
		{
			m_Particle_ptr[i].update();
		}
	}

} /*Namespace judg3*/