#pragma once

#include <random>
#include <chrono>

#include "trPrerequisite.h"
#include "trMath.h"

namespace tr
{
	//Random 1D double number range [0,1)
	class RNG
	{
	public:
		RNG():_generator(std::chrono::system_clock::now().time_since_epoch().count()),_distribution(0.0,1.0)
		{}

		inline double random ()
		{return _distribution(_generator);}
	private:
		std::default_random_engine _generator;
		std::uniform_real_distribution<double> _distribution;
	};

	class Sampler
	{
	public:
		float sample1D ();				//[0,1)
		Vector2f sample2D ();			//[0,1)*[0,1)
		Vector3f sample3D ();			//[0,1)*[0,1)*[0,1)
		Vector3f sampleHemiSphere (const Vector3f & normal);		//Sample unit hemisphere
		//Vector3f sampleSphere ();									//Sample unit sphere
		//Vector3f sampleCone ();
	private:
		RNG _rng;
	};
}