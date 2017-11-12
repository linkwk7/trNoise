#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trShape.h"

namespace tr
{
	class Plane : public Shape
	{
	public:
		Plane(const Point3f & p,const Normal3f & n):_position(p),_normal(n)
		{}

		bool intersect(const Ray & r,intersectInfo & ii) const override;
		bool shadowIntersect (const Ray & r) const override;
		void sample(const Point3f & p,Vector3f & wi,float & dis,float & pdf) const override;
	private:
		Point3f _position;
		Normal3f _normal;
	};
}
