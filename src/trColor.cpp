#include "trColor.h"

namespace tr
{
	Color Color::clamp () const
	{
		return Color(tr::clamp(r,0.0f,1.0f),tr::clamp(g,0.0f,1.0f),tr::clamp(b,0.0f,1.0f));
	}

	Color Color::operator+ (const Color & c) const
	{
		return Color(r+c.r,g+c.g,b+c.b);
	}

	Color Color::operator* (float s) const
	{
		return Color(r*s,g*s,b*s);
	}

	Color Color::operator/ (float s) const
	{
		float inv = 1.0f/s;
		return Color(r*inv,g*inv,b*inv);
	}

	Color & Color::operator= (const Color & c)
	{
		r = c.r;g = c.g;b = c.b;
		return *this;
	}

	Color spectrum2Color(const Spectrum & spe)
	{
		return Color(spe.x,spe.y,spe.z).clamp();
	}

	Spectrum color2Spectrum(const Color & clr)
	{
		return Spectrum(clr.r,clr.g,clr.b);
	}

	/*truint32 Color::compressColor() const
	{
		Color clampColor = clampColor();
		truint32 clr = 0;
		clr = clr | 255;
		clr = clr | (static_cast<int>(clampColor.b * 255) << 8);
		clr = clr | (static_cast<int>(clampColor.g * 255) << 16);
		clr = clr | (static_cast<int>(clampColor.r * 255) << 24);
		return clr;
	}*/
}
