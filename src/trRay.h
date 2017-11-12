#pragma once

#include <iostream>

#include "trPrerequisite.h"
#include "trMath.h"

namespace tr
{
	class Ray
	{
	public:
		Ray (const Point3f & oo,const Vector3f & dd,float min=0,float max=Infinity):o(oo),d(normalize(dd)),tMin(min),tMax(max)
		{}
		Ray (const Ray & r):o(r.o),d(r.d),tMin(r.tMin),tMax(r.tMax)
		{}

		Point3f at (float t) const
		{
			return o+t*d;
		}
		Ray & operator= (const Ray & r)
		{
			o = r.o;
			d = r.d;
			return *this;
		}

		Point3f o;
		Vector3f d;
		mutable float tMin,tMax;
	private:
	};

	std::ostream & operator<< (std::ostream & os,const Ray & r);
	Ray operator* (const Matrix4f & m,const Ray & r);
}