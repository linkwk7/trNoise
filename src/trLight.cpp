#include "trLight.h"

namespace tr
{
	Spectrum PointLight::sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const
	{
		wi = _position - p;
		dis = wi.length();
		wi = wi/dis;
		pdf = 1.0f;
		return _intensity /(dis*dis);
	}

	Spectrum SpotLight::sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const
	{
		wi = _position - p;
		dis = wi.length();
		wi = normalize(wi);
		pdf = 1.0f;
		return _intensity*fallout(-wi)/(dis*dis);
	}

	float SpotLight::fallout (const Vector3f & mwi) const
	{
		Vector3f wl = normalize(mwi);
		float c = dot(wl,_direction);
		if (c < _cosTotalWidth)		return 0.0f;
		if (c > _cosFallStart)		return 1.0f;
		float delta = (c - _cosTotalWidth)/(_cosFallStart - _cosTotalWidth);
		delta = delta*delta;
		return delta*delta;
	}

	Spectrum AreaLight::sampleLight (const Point3f & p,Vector3f & wi,float & dis,float & pdf) const
	{
		_shape->sample(p,wi,dis,pdf);
		return _intensity;
	}
}
