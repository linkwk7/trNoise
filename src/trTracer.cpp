#include <omp.h>

#include "trTracer.h"

namespace tr
{
	void Tracer::render (const std::string & file)
	{
		BMP bmp(_width,_height,file);

		float inv = 1.0f/_spp;
		#pragma omp parallel num_threads(5)
        #pragma omp parallel for schedule(dynamic)
		for (int y=0;y<_height;++y)
		{
			for (int x=0;x<_width;++x)
			{
				Point2f pt (x,y);
				Spectrum spe (0,0,0);
				for (int s=0;s<_spp;++s)
				{
					Vector2f offset = _sampler.sample2D ();
					Point2f tp = pt+offset;
					Ray pr = _camera.generateRay (tp);

					spe += trace(pr,0);
				}
				spe *= inv;
				bmp(x,y) = spectrum2Color (spe);
			}
		}
		bmp.saveImage();
	}

	Spectrum Tracer::trace (const Ray & r,int depth)
	{
		intersectInfo ii;
		for (size_t g=0,gsz=_geometry.size();g<gsz;++g)
			_geometry[g]->intersect(r,ii);
		if (ii.hit() == false)
			return Spectrum(0,0,0);

		if (ii.g->isLight())
		{
			const AreaLight * al = ii.g->getAreaLight();
			return al->radiance();
		}

		float pdf = 0.0f;
		Vector3f reflDir = Vector3f(0,0,0);
		const BSDF * bsdf = ii.g->getBSDF();
		Spectrum refl = bsdf->sampleF(ii.v.normal,r.d,reflDir,pdf);

		Point3f reflOri = ii.v.position + reflDir * Epsilon;
		Ray reflRay (reflOri,reflDir);

		Spectrum dl (0,0,0);
		if (bsdf->type() == BSDF::Diffuse)
		{
			for (size_t l=0,lsz=_lights.size();l<lsz;++l)
			{
				for (int lsample=0;lsample<_lights[l]->samples();++lsample)
				{
					Vector3f lightDir = Vector3f(0,0,0);
					float ldistance = 0.0f;
					float lpdf = 0.0f;
					Spectrum radiance=_lights[l]->sampleLight(reflOri,lightDir,ldistance,lpdf);
					Ray shadowRay (reflOri,lightDir,0.0f,ldistance);

					bool obstacle=false;

					if (lightDir==Vector3f(0,0,0) || dot(lightDir,Vector3f(ii.v.normal)) < 0)
						continue;
					for (size_t g=0,gsz=_geometry.size();g<gsz;++g)
						if (_geometry[g]->shadowIntersect(shadowRay))
						{
							obstacle = true;
							break;
						}
					if (obstacle == false)
					{
						Spectrum lrefl = bsdf->f(r.d,reflDir);
						dl += mult(radiance,lrefl)*absDot(Vector3f(ii.v.normal),reflDir)/lpdf;
					}
				}
			}
		}

		float avg = (refl.x+refl.y+refl.z)/3;
		if (depth > 3 && (_sampler.sample1D() > avg || depth > 7))
			return dl;
		
		//Temporary solution
		if (bsdf->type() == BSDF::Reflect)
		{
			return dl+trace(reflRay,depth+1);
		}
		Spectrum il = mult(trace(reflRay,depth+1),refl) * absDot(Vector3f(ii.v.normal),reflDir);
		return dl + il/(pdf*avg);
	}
}
