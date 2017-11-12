#pragma once

#include "trPrerequisite.h"
#include "trMath.h"

namespace tr
{
	class Color
	{
	public:
		Color ():r(0.0f),g(0.0f),b(0.0f)
		{}
		Color (const Color & c):r(c.r),g(c.g),b(c.b)
		{}
		Color (float rr,float gg,float bb):r(rr),g(gg),b(bb)
		{}

		Color clamp () const;
		Color operator+ (const Color & c) const;
		Color operator* (float s) const;
		Color operator/ (float s) const;
		Color & operator= (const Color & c);
		//truint32 compressColor() const;

		float r,g,b;
	private:
	};

	Color spectrum2Color(const Spectrum & spe);
	Spectrum color2Spectrum(const Color & clr);
}
