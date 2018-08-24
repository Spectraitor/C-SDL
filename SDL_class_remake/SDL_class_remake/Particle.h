#pragma once

#ifndef PARTICLE_H
#define PARTICLE_H

namespace judg3
{

	class Particle
	{
	public:
		double m_x;
		double m_y;

	private:
		double m_xspeed;
		double m_yspeed;


	public:
		Particle();
		~Particle();
		void update();
	};

}/*Namespace judg3*/

#endif /*PARICLE_H*/
