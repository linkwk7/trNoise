#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trSampler.h"
#include "trIntersectInfo.h"

namespace tr
{
	//wo from eye to hit point,wi from hit point to light
	//All direction is normalized
	class BSDF
	{
	public:
		enum Type
		{
			Diffuse = 1,
			Reflect = 2,
			Refract = 4,
			Emission = 8
		};

		virtual ~BSDF()
		{}

		virtual Type type () const = 0;
		virtual Spectrum f (const Vector3f & wo,const Vector3f & wi) const = 0;
		virtual Spectrum sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const = 0;
		virtual Spectrum emission () const = 0;
		virtual bool isDelta () const = 0;
	private:
	};

	class DiffuseBSDF : public BSDF
	{
	public:
		DiffuseBSDF(const Spectrum & r):_r(r)
		{}

		Type type () const override
		{return BSDF::Diffuse;}
		Spectrum f (const Vector3f & wo,const Vector3f & wi) const override;
		Spectrum sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const override;
		Spectrum emission () const override
		{return Spectrum(0,0,0);}
		bool isDelta () const override
		{return false;}
	private:
		Spectrum _r;
	};

	class ReflectBSDF : public BSDF
	{
	public:
		ReflectBSDF(const Spectrum & r):_reflectance(r)
		{}

		Type type () const override
		{return BSDF::Reflect;}
		Spectrum f (const Vector3f & wo,const Vector3f & wi) const override;
		Spectrum sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const override;
		Spectrum emission () const override
		{return Spectrum(0,0,0);}
		bool isDelta () const override
		{return true;}
	private:
		Spectrum _reflectance;
	};

	class RefractBSDF : public BSDF
	{
	public:
		RefractBSDF(float t):_transmittance(t)
		{}

		Type type () const override
		{return BSDF::Refract;}
		Spectrum f (const Vector3f & wo,const Vector3f & wi) const override;
		Spectrum sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const override;
		Spectrum emission () const override
		{return Spectrum(0,0,0);}
		bool isDelta () const override
		{return true;}
	private:
		float _transmittance;
	};

	/*class EmissionBSDF : public BSDF
	{
	public:
		EmissionBSDF (const Spectrum & e):_e(e)
		{}

		Type type () const override
		{return BSDF::Emission;}
		Spectrum f (const Vector3f & wo,const Vector3f & wi) const override;
		Spectrum sampleF (const Normal3f & n,const Vector3f & wo,Vector3f & wi,float & pdf) const override;
		Spectrum emission () const override
		{return _e;}
		bool isDelta () const override
		{return false;}
	private:
		Spectrum _e;
	};*/
}
