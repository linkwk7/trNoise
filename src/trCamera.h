#pragma once

#include "trPrerequisite.h"
#include "trMath.h"
#include "trRay.h"

namespace tr
{
	class Camera
	{
	public:
		Camera(const Point3f & ori,const Point3f & atl,const Vector3f & up,\
				float fov,\
				const Vector2i & res,float fl,\
				float rad)
		{
			_camera2World = lookAt(ori,atl,up);
			Matrix4f camera2Screen = perspective (fov,1,1000);

            float vd = std::tan(radians(fov/2))*2.0*fl;
			float aspectRatio = static_cast<float>(res.x) / res.y;
            float screen[4];
            screen[0] = aspectRatio*vd/2;
            screen[1] = -screen[0];
            screen[2] = -vd/2;
            screen[3] = -screen[2];
            Matrix4f screen2Raster = scale(res.x,res.y,1.0f)\
                                     * scale(1.0f/(screen[1]-screen[0]),1.0f/(screen[2]-screen[3]),1.0f)\
                                     * translate(Vector3f(-screen[0],-screen[3],0));
			_raster2Camera = camera2Screen.inverse()*screen2Raster.inverse();
		}

		Ray generateRay (const Point2f & p) const;
	private:
		Vector3f _origin;
		Matrix4f _camera2World;
		Matrix4f _raster2Camera;
	};
}
