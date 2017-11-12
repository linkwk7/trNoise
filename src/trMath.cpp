#include "trMath.h"

namespace tr
{
	void coordinateSystem (const Vector3f & v1,Vector3f & v2,Vector3f & v3)
	{
		if (std::abs(v1.x) > std::abs(v1.y))
		{
			float invLen = 1.0f/std::sqrt(v1.x*v1.x+v1.z*v1.z);
			v2 = Vector3f(-v1.z*invLen,0.0f,v1.x*invLen);
		}
		else
		{
			float invLen = 1.0f/std::sqrt(v1.y*v1.y+v1.z*v1.z);
			v2 = Vector3f(0.0f,v1.z*invLen,-v1.y*invLen);
		}
		v3 = cross(v1,v2);
	}

	Matrix4f translate (const Vector3f & ve)
	{
		return Matrix4f (1, 0, 0, ve.x,
						 0, 1, 0, ve.y,
						 0, 0, 1, ve.z,
						 0, 0, 0, 1);
	}

	Matrix4f scale (float x,float y,float z)
	{
		return Matrix4f (x, 0, 0, 0,
						 0, y, 0, 0,
						 0, 0, z, 0,
						 0, 0, 0, 1);
	}

	Matrix4f rotateX (float degree)
	{
		float s = std::sin(radians(degree));
		float c = std::cos(radians(degree));
		return Matrix4f(1, 0, 0, 0,
						0, c, -s, 0,
						0, s, c, 0,
						0, 0, 0, 1);
	}

	Matrix4f rotateY (float degree)
	{
		float s = std::sin(radians(degree));
		float c = std::cos(radians(degree));
		return Matrix4f(c, 0, s, 0,
						0, 1, 0, 0,
						-s, 0, c, 0,
						0, 0, 0, 1);
	}

	Matrix4f rotateZ (float degree)
	{
		float s = std::sin(radians(degree));
		float c = std::cos(radians(degree));
		return Matrix4f(c, -s, 0, 0,
						s, c, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1);
	}

	Matrix4f rotate (const Vector3f & axis,float degree)
	{
		Vector3f a = normalize(axis);
		float s = std::sin(radians(degree));
		float c = std::cos(radians(degree));
		Matrix4f m;
		m(0,0) = a.x * a.x + (1 - a.x * a.x) * c;
		m(0,1) = a.x * a.y * (1 - c) - a.z * s;
		m(0,2) = a.x * a.z * (1 - c) + a.y * s;
		m(0,3) = 0;

		m(1,0) = a.x * a.y * (1 - c) + a.z * s;
		m(1,1) = a.y * a.y + (1 - a.y * a.y) * c;
		m(1,2) = a.y * a.z * (1 - c) - a.x * s;
		m(1,3) = 0;

		m(2,0) = a.x * a.z * (1 - c) - a.y * s;
		m(2,1) = a.y * a.z * (1 - c) + a.x * s;
		m(2,2) = a.z * a.z + (1 - a.z * a.z) * c;
		m(2,3) = 0;

		m(3,0) = 0;m(3,1) = 0;m(3,2) = 0;m(3,3) = 1;
		return m;
	}

	Matrix4f orthographic (float near,float far)
	{
		return scale (1.0f,1.0f,1.0f/(far-near)) * translate(Vector3f(0.0f,0.0f,-near));
	}

	Matrix4f perspective (float fov,float near,float far)
	{
		float inv = 1.0f/std::tan(radians(fov)/2.0f);
		return Matrix4f (inv, 0, 0, 0,
					   0, inv, 0, 0,
					   0, 0, far/(far-near), -far*near/(far-near),
					   0, 0, 1, 0);
	}

	Matrix4f lookAt (const Point3f & pos,const Point3f & at,const Vector3f & up)
	{
		Vector3f w (normalize(at-pos));
		Vector3f u (normalize(cross(up,w)));
		Vector3f v (normalize(cross(w,u)));
		return Matrix4f	(u.x,v.x,w.x,pos.x,
						 u.y,v.y,w.y,pos.y,
						 u.z,v.z,w.z,pos.z,
						 0,  0,  0,  1);
	}
}
