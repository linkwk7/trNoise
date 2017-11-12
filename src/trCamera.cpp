#include "trCamera.h"

namespace tr
{
	Ray Camera::generateRay (const Point2f & p) const
	{
		Point3f pt = _raster2Camera*Point3f(p.x,p.y,0);
		Ray r (Point3f(0,0,0),normalize(Vector3f(pt.x,pt.y,pt.z)));
		return _camera2World*r;
	}
}
