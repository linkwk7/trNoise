#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

#include "trPrerequisite.h"
#include "trGeometry.h"
#include "trLight.h"
#include "trSampler.h"
#include "trCamera.h"
#include "trImage.h"

namespace tr
{
	class Tracer
	{
	public:
		Tracer(int w,int h,const std::vector<Geometry*> & ge,const std::vector<Light*> & l,const Camera & c,int spp=51):\
			_width(w),_height(h),_geometry(ge),_lights(l),_camera(c),_spp(spp),_sampler()
		{}

		void render (const std::string & file);
	private:
		Spectrum trace (const Ray & r,int depth);
		Spectrum pathTracing (const Ray & r);

		int _width;
		int _height;
		std::vector<Geometry *> _geometry;
		std::vector<Light *> _lights;
		Camera _camera;

		int _spp;

		Sampler _sampler;
	};
}
