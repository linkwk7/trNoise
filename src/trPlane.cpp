#include "trPlane.h"

namespace tr
{
	bool Plane::intersect(const Ray & r,intersectInfo & ii) const
	{
		float denom = dot(r.d,Vector3f(_normal));
		if (denom > 0)
		{
			return false;
		}
		else
		{
			float t = -dot(r.o - _position, Vector3f(_normal))/denom;
			if (t > r.tMin && t < r.tMax && t < ii.t)
			{
				ii.t = t;
				ii.v.position = r.at(t);
				ii.v.normal = _normal;
				return true;
			}
			return false;
		}
	}

	bool Plane::shadowIntersect(const Ray & r) const
	{
		float denom = dot(r.d,Vector3f(_normal));
		if (denom > 0)
		{
			return false;
		}
		else
		{
			float t = -dot(r.o - _position, Vector3f(_normal))/denom;
			return (t > r.tMin && t < r.tMax);
		}
	}

	void Plane::sample(const Point3f & p,Vector3f & wi,float & dis,float & pdf) const
	{
		//Not implement yet
		Assert (0);
	}
}
