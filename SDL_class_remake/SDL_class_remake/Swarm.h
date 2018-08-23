#pragma once

#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace judg3
{

	class Swarm
	{
	public:
		const static int NPARTICLES = 200000;

	private:
		Particle * m_Particle_ptr;

	public:
		Swarm();
		~Swarm();

		const Particle* const getParticles() { return m_Particle_ptr; }
	};

}
#endif