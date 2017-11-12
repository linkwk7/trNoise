#include "trSphere.h"

namespace tr
{
	bool Sphere::intersect(const Ray & r,intersectInfo & ii) const
	{
		Vector3f l = _center - r.o;
        float tca = dot(l, r.d);
        float l2 = l.length2();
        if ((tca < 0.0f) && (l2 > _radius2))
            return false;
        float d2 = l2 - tca*tca;
        if (d2 > _radius2)
            return false;
        float thc = std::sqrt(_radius2 - d2);
        float t0 = tca-thc,t1 = tca+thc;
        float t = ((l2>_radius2) ? t0:t1);

        if (t < ii.t && t<r.tMax && t>r.tMin)
        {
            Point3f hitPos(r.at(t));

            ii.t = t;
            ii.v.position = hitPos;
            ii.v.normal = Normal3f(normalize(hitPos-_center));
            return true;
        }
        else
        {
            return false;
        }
	}

    bool Sphere::shadowIntersect(const Ray & r) const
    {
        Vector3f l = _center - r.o;
        float tca = dot(l, r.d);
        float l2 = l.length2();
        if ((tca < 0.0f) && (l2 > _radius2))
            return false;
        float d2 = l2 - tca*tca;
        if (d2 > _radius2)
            return false;
        float thc = std::sqrt(_radius2 - d2);
        float t0 = tca-thc,t1 = tca+thc;
        float t = ((l2>_radius2) ? t0:t1);
        return (t<r.tMax && t>r.tMin);
    }

    void Sphere::sample(const Point3f & p,Vector3f & wi,float & dis,float & pdf) const
    {
        Vector3f sz = normalize(_center-p);
        Vector3f sx(0,0,0),sy(0,0,0);
        coordinateSystem (sz,sx,sy);

        float cosAMax = std::sqrt(std::max(0.0,1.0f - _radius2/(_center-p).length2()));
        float eps1 = _sampler.sample1D(),eps2 = _sampler.sample1D();
        float cosA = 1.0f - eps1 + eps1*cosAMax;
        float sinA = std::sqrt(1.0f-cosA*cosA);
        float phi = 2 * PI * eps2;
        wi = sx*std::cos(phi)*sinA + sy*std::sin(phi)*sinA + sz*cosA;
        dis = (_center-p).length();
        wi = wi/dis;
        pdf = 1.0f/(DPI*(1.0f-cosAMax));
    }
}
