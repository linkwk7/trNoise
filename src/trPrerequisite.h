#pragma once

#include <assert.h>
#include <limits>
#include <iostream>
#include <cstdint>

#define DEBUG

typedef float trfloat;
typedef int trint;
typedef unsigned char	trbyte;
typedef unsigned int	truint32;

namespace tr
{
#ifdef DEBUG
	void Assert (int expression);
	//#define Assert assert
#endif

const trfloat PI = 3.1415926535898;
const trfloat DPI = 6.2831853071796;
const trfloat INVPI = 0.3183098861837;
const trfloat Infinity = std::numeric_limits<trfloat>::max();
const float fInfinity = std::numeric_limits<float>::max();
const double dInfinity = std::numeric_limits<double>::max();
const float Epsilon = 1e-6;
}
