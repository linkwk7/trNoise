#include "trSampler.h"

namespace tr
{
	float Sampler::sample1D ()
	{
		return _rng.random();
	}

	Vector2f Sampler::sample2D ()
	{
		return Vector2f(_rng.random(),_rng.random());
	}

	Vector3f Sampler::sample3D ()
	{
		return Vector3f(_rng.random(),_rng.random(),_rng.random());
	}

	Vector3f Sampler::sampleHemiSphere (const Vector3f & normal)
	{
		Vector3f u, v, w(normal);

		if (std::fabs(w.x) > std::fabs(w.y))
			u = normalize(cross(Vector3f(0, 1, 0), w));
		else
			u = normalize(cross(Vector3f(1, 0, 0), w));
		v = cross(w, u);

		float eps1 = _rng.random(), eps2 = _rng.random(), sini = std::sqrt(eps1), cosi = 2*PI*eps2;
		return normalize((sini*std::cos(cosi)*u) + (sini*std::sin(cosi)*v) + (std::sqrt(1-eps1)*w));
	}
}