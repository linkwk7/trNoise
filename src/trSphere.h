#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trShape.h"
#include "trIntersectInfo.h"
#include "trSampler.h"

namespace tr
{
	class Sphere : public Shape
	{
	public:
		Sphere (const Point3f & c,float r):_center(c),_radius(r),_radius2(r*r)
		{}

		bool intersect(const Ray & r,intersectInfo & ii) const override;
		bool shadowIntersect(const Ray & r) const override;
		void sample(const Point3f & p,Vector3f & wi,float & dis,float & pdf) const override;
	private:
		Point3f _center;
		float _radius;
		float _radius2;
	};
}