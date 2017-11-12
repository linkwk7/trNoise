#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trIntersectInfo.h"
#include "trRay.h"
#include "trBSDF.h"
#include "trSampler.h"

namespace tr
{
	class Shape
	{
	public:

		virtual ~Shape()
		{}

		//Only if current object intersect with ray and is near than last intersect object then return true
		virtual bool intersect(const Ray & r,intersectInfo & ii) const = 0;
		virtual bool shadowIntersect (const Ray & r) const = 0;
		//wi from hit point to light
		virtual void sample(const Point3f & p,Vector3f & wi,float & dis,float & pdf) const = 0;
	protected:
		static Sampler _sampler;
	private:
	};
}
