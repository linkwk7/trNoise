#include "trRay.h"

namespace tr
{
	std::ostream & operator<< (std::ostream & os,const Ray & r)
	{
		os<<"[r: o="<<r.o<<" d="<<r.d<<"]";
		return os;
	}

	Ray operator* (const Matrix4f & m,const Ray & r)
	{
		return Ray (m*r.o,normalize(m*r.d));
	}
}