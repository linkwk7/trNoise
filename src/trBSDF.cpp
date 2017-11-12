#include "trBSDF.h"

namespace tr
{
	static Sampler sampler;

	Spectrum DiffuseBSDF::f (const Vector3f & wo,const Vector3f & wi) const
	{
		return _r * INVPI;
	}

	Spectrum DiffuseBSDF::sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const
	{
		wi = sampler.sampleHemiSphere(Vector3f(n));
		pdf = 1.0f/2*PI;
		return f(wo, wi);
	}

	Spectrum ReflectBSDF::f (const Vector3f & wo,const Vector3f & wi) const
	{
		return Spectrum(0,0,0);
	}

	Spectrum ReflectBSDF::sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const
	{
		float cosT = dot(Vector3f(n), -wo);
		wi = normalize(wo + Vector3f(n) * (2 * cosT));
		pdf = 1.0f;
		return _reflectance/std::abs(cosT);
	}

	Spectrum RefractBSDF::f (const Vector3f & wo,const Vector3f & wi) const
	{
		return Spectrum(0,0,0);
	}

	Spectrum RefractBSDF::sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const
	{
		Vector3f normal (n);
		float cosI = dot(normal, wo);
		bool entering = cosI < 0.0f;
		cosI = std::abs(cosI);
		
		float eiseo = (entering? 1.0f/_transmittance:_transmittance);
		float sinI = std::max(0.0f, 1.0f - cosI * cosI);
		float sinT = eiseo * eiseo * sinI;
		if (sinT >= 1.0f)
		{
			wi = normalize (wo + normal*2*dot(normal,-wo));
			return Spectrum(0,0,0);
		}

		float cosT = std::sqrt(1 - sinT);
		wi = normalize(wo*eiseo - normal*((entering ? 1 : -1)*((eiseo*cosI)+cosT)));
		pdf = 1.0f;
		return Spectrum(_transmittance,_transmittance,_transmittance)/std::abs(cosI);
	}
}
