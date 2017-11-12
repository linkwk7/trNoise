#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trShape.h"

namespace tr
{
	class Light
	{
	public:
		Light(const Spectrum & i,int ns=1):_intensity(i),_samples(ns)
		{}

		virtual ~Light()
		{}

		virtual bool isDelta () const = 0;
		//wi direction : hit point -> light source
		virtual Spectrum sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const = 0;
		int samples () const
		{return _samples;}
	protected:
		Spectrum _intensity;
		int _samples;
	};

	class PointLight : public Light
	{
	public:
		PointLight (const Spectrum & i,const Point3f & p):Light(i),_position(p)
		{}

		bool isDelta () const override
		{return true;}
		Spectrum sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const override;
	private:
		Point3f _position;
	};

	class SpotLight : public Light
	{
	public:
		SpotLight (const Spectrum & i,const Point3f & p,const Vector3f & dir,float wid,float fall):\
			Light(i),_position(p),_direction(normalize(dir)),_cosTotalWidth(std::cos(radians(wid))),_cosFallStart(std::cos(radians(fall)))
		{}

		bool isDelta () const override
		{return true;}
		Spectrum sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const override;
	private:
		//mwi from light
		float fallout (const Vector3f & mwi) const;

		Point3f _position;
		//from light
		Vector3f _direction;
		float _cosTotalWidth;
		float _cosFallStart;
	};

	//Every arealight bind with a shape,when add an arealight to scence light vector,
	// a geometroy need add to scence shape vector
	class AreaLight : public Light
	{
	public:
		AreaLight (const Spectrum & i,const Shape * s):Light(i,7),_shape(s)
		{}

		bool isDelta() const override
		{return false;}
		Spectrum sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const override;
		Spectrum radiance () const
		{return _intensity;}
	private:
		const Shape * _shape;
	};
}
