#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trShape.h"
#include "trBSDF.h"
#include "trIntersectInfo.h"
#include "trLight.h"

namespace tr
{
	class Geometry
	{
	public:
		Geometry (const BSDF * b,const Shape * s,const AreaLight * l=nullptr):\
			_bsdf(b),_shape(s),_light(l)
		{}

		inline bool intersect(const Ray & r,intersectInfo & ii) const
		{
			bool status = _shape->intersect(r,ii);
			if (status==true)	ii.g=this;
			return status;
		}
		inline bool shadowIntersect(const Ray & r) const
		{
			return _shape->shadowIntersect(r);
		}
		inline bool isLight () const
		{return (_light!=nullptr);}

		const BSDF * getBSDF() const
		{return _bsdf;}
		const AreaLight * getAreaLight() const
		{return _light;}
	private:
		const BSDF * _bsdf;
		const Shape * _shape;
		const AreaLight * _light;
	};
}
