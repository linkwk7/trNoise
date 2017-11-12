#pragma once

#include "trPrerequisite.h"
#include "trVertex.h"

namespace tr
{
	class Geometry;

	class intersectInfo
	{
	public:
		intersectInfo(float tt=Infinity,const Vertex & vv=Vertex(),const Geometry * gp=nullptr):\
			t(tt),v(vv),g(gp)
		{}

		bool hit () const
		{return t!=Infinity;}

		float t;
		Vertex v;
		const Geometry * g;
	private:
	};
}
