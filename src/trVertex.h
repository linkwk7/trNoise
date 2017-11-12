#pragma once

#include "trPrerequisite.h"
#include "trMath.h"

namespace tr
{
	class Vertex
	{
	public:
		Vertex ()
		{}
		Vertex (const Point3f & pp,const Normal3f & nn,const Point2f & u):position(pp),normal(nn),uv(u)
		{}

		Point3f position;
		Normal3f normal;
		Point2f uv;
	};
}
