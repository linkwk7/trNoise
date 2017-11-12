#pragma once

#include <algorithm>
#include <cmath>

#include "trPrerequisite.h"

namespace tr
{
	template <typename T>
	class Vector2;
	template <typename T>
	class Vector3;

	//Point
	template <typename T>
	class Point2
	{
	public:
		Point2 ():x(0),y(0)
		{}
		Point2 (T xx,T yy):x(xx),y(yy)
		{}
		Point2 (const Point2<T> & p):x(p.x),y(p.y)
		{}
		explicit Point2 (const Vector2<T> & v):x(v.x),y(v.y)
		{}

		//Operator overload
		Point2<T> & operator= (const Point2<T> & arg)
		{
			x = arg.x;
			y = arg.y;
			return *this;
		}
		Point2<T> operator+ (const Vector2<T> & arg) const
		{
			return Point2<T>(x + arg.x, y + arg.y);
		}
		Point2<T> & operator+= (const Vector2<T> & arg)
		{
			x += arg.x;
			y += arg.y;
			return *this;
		}
		Point2<T> operator- (const Vector2<T> & arg) const
		{
			return Point2<T>(x - arg.x, y - arg.y);
		}
		Point2<T> & operator-= (const Vector2<T> & arg)
		{
			x -= arg.x;
			y -= arg.y;
			return *this;
		}
		Vector2<T> operator- (const Point2<T> & arg) const
		{
			return Vector2<T> (x-arg.x,y-arg.y);
		}
		bool operator== (const Point2<T> & arg) const
		{
			return (x == arg.x && y == arg.y);
		}
		bool operator!= (const Point2<T> & arg) const
		{
			return (x != arg.x || y!=arg.y);
		}
		T operator[] (int i) const
		{
			Assert(i==0 || i==1);
			return (i == 0) ? x : y;
		}
		T & operator[] (int i)
		{
			Assert(i == 0 || i == 1);
			return (i == 0) ? x : y;
		}

		//friend function
		friend std::ostream & operator<< (std::ostream & os,const Point2 & p)
		{
			os<<"(p2:"<<p.x<<","<<p.y<<")";
			return os;
		}

		//Public data member
		T x,y;
	private:
	};

	template <typename T>
	class Point3
	{
	public:
		Point3():x(0),y(0),z(0)
		{}
		Point3(const T & xx,const T & yy,const T & zz):x(xx),y(yy),z(zz)
		{}
		Point3(const Point3<T> & p):x(p.x),y(p.y),z(p.z)
		{}
		explicit Point3(const Vector3<T> & v):x(v.x),y(v.y),z(v.z)
		{}

		Point3<T> & operator=(const Point3<T> & arg)
		{
			x = arg.x;
			y = arg.y;
			z = arg.z;
			return *this;
		}
		Point3<T> operator+ (const Vector3<T> & arg) const
		{
			return Point3<T>(x + arg.x, y + arg.y, z + arg.z);
		}
		Point3<T> & operator+= (const Vector3<T> & arg)
		{
			x = x + arg.x;
			y = y + arg.y;
			z = z + arg.z;
			return *this;
		}
		Point3<T> operator- (const Vector3<T> & arg) const
		{
			return Point3<T>(x - arg.x, y - arg.y, z - arg.z);
		}
		Point3<T> & operator-= (const Vector3<T> & arg)
		{
			x = x - arg.x;
			y = y - arg.y;
			z = z - arg.z;
			return *this;
		}
		Vector3<T> operator- (const Point3<T> & arg) const
		{
			return Vector3<T>(x-arg.x,y-arg.y,z-arg.z);
		}
		bool operator== (const Point3<T> & arg) const
		{
			return (x == arg.x && y == arg.y && z == arg.z);
		}
		bool operator!= (const Point3<T> & arg) const
		{
			return !(*this == arg);
		}
		T operator[] (int i) const
		{
			Assert(i == 0 || i == 1 || i == 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		T & operator[] (int i)
		{
			Assert(i == 0 || i == 1 || i == 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}

		//friend function
		friend std::ostream & operator<< (std::ostream & os,const Point3 & v)
		{
			os<<"(p3:"<<v.x<<","<<v.y<<","<<v.z<<")";
			return os;
		}

		//Public data member
		T x, y, z;
	private:
	};

	typedef Point2<float> Point2f;
	typedef Point2<int> Point2i;
	typedef Point3<float> Point3f;

	template <typename T>
	inline T distance (const Point3<T> & p1,const Point3<T> & p2)
	{
		return (p1-p2).length();
	}

	template <typename T>
	inline T distance2 (const Point3<T> & p1,const Point3<T> & p2)
	{
		return (p1-p2).length2();
	}

	//Vector
	template <typename T>
	class Vector2
	{
	public:
		//Constructor
		Vector2(): x(0),y(0)
		{}
		Vector2(const T & xx, const T & yy) :x(xx), y(yy)
		{}
		Vector2(const Vector2<T> & arg):x(arg.x),y(arg.y)
		{}
		explicit Vector2(const Point2<T> & p):x(p.x),y(p.y)
		{}

		//Operator overload
		Vector2<T> & operator= (const Vector2<T> & arg)
		{
			x = arg.x;
			y = arg.y;
			return *this;
		}
		Vector2<T> operator+ (const Vector2<T> & arg) const
		{
			return Vector2<T>(x + arg.x, y + arg.y);
		}
		Vector2<T> & operator+= (const Vector2<T> & arg)
		{
			x += arg.x;
			y += arg.y;
			return *this;
		}
		Vector2<T> operator- (const Vector2<T> & arg) const
		{
			return Vector2<T>(x - arg.x, y - arg.y);
		}
		Vector2<T> & operator-= (const Vector2<T> & arg)
		{
			x -= arg.x;
			y -= arg.y;
			return *this;
		}
		Point2<T> operator+ (const Point2<T> & arg) const
		{
			return Point2<T> (x+arg.x,y+arg.y);
		}
		bool operator== (const Vector2<T> & arg) const
		{
			return (x == arg.x && y == arg.y);
		}
		bool operator!= (const Vector2<T> & arg) const
		{
			return (x != arg.x || y!=arg.y);
		}
		template <typename U>
		Vector2<T> operator* (const U & arg) const
		{
			return Vector2<T>(x*arg, y*arg);
		}
		template <typename U>
		Vector2<T> & operator*= (const U & arg)
		{
			x = x*arg;
			y = y*arg;
			return *this;
		}
		template <typename U>
		Vector2<T> operator/ (const U & arg) const
		{
			Assert(arg != 0);
			U inv = 1.0/arg;
			return Vector2<T>(x * inv, y * inv);
		}
		template <typename U>
		Vector2<T> & operator/= (const U & arg)
		{
			Assert(arg != 0);
			U inv = 1.0/arg;
			x = x * inv;
			y = y * inv;
			return *this;
		}
		Vector2<T> operator-() const
		{
			return Vector2<T>(-x, -y);
		}
		T operator[] (int i) const
		{
			Assert(i==0 || i==1);
			return (i == 0) ? x : y;
		}
		T & operator[] (int i)
		{
			Assert(i == 0 || i == 1);
			return (i == 0) ? x : y;
		}

		//member function
		double length() const
		{
			return std::sqrt(x*x + y*y);
		}
		double length2() const
		{
			return x*x+y*y;
		}

		//friend function
		template <typename U>
		friend Vector2<T> operator* (U t, const Vector2<T> & arg)
		{
			return Vector2<T>(t*arg.x, t*arg.y);
		}
		friend std::ostream & operator<< (std::ostream & os,const Vector2 & v)
		{
			os<<"(v2:"<<v.x<<","<<v.y<<")";
			return os;
		}

		//Public data member
		T x, y;
	private:
	};

	template <typename T>
	class Normal3;

	template <typename T>
	class Vector3
	{
	public:
		Vector3():x(0),y(0),z(0)
		{}
		Vector3(const T & xx,const T & yy,const T & zz):x(xx),y(yy),z(zz)
		{}
		Vector3(const Vector3<T> & arg):x(arg.x),y(arg.y),z(arg.z)
		{}
		explicit Vector3(const Point3<T> & p):x(p.x),y(p.y),z(p.z)
		{}
		explicit Vector3(const Normal3<T> & n):x(n.x),y(n.y),z(n.z)
		{}

		Vector3<T> & operator=(const Vector3<T> & arg)
		{
			x = arg.x;
			y = arg.y;
			z = arg.z;
			return *this;
		}
		Vector3<T> operator+ (const Vector3<T> & arg) const
		{
			return Vector3<T>(x + arg.x, y + arg.y, z + arg.z);
		}
		Vector3<T> & operator+= (const Vector3<T> & arg)
		{
			x = x + arg.x;
			y = y + arg.y;
			z = z + arg.z;
			return *this;
		}
		Vector3<T> operator- (const Vector3<T> & arg) const
		{
			return Vector3<T>(x - arg.x, y - arg.y, z - arg.z);
		}
		Vector3<T> & operator-= (const Vector3<T> & arg)
		{
			x = x - arg.x;
			y = y - arg.y;
			z = z - arg.z;
			return *this;
		}
		Point3<T> operator+ (const Point3<T> & arg) const
		{
			return Point3<T> (x+arg.x,y+arg.y,z+arg.z);
		}
		bool operator== (const Vector3<T> & arg) const
		{
			return (x == arg.x && y == arg.y && z == arg.z);
		}
		bool operator!= (const Vector3<T> & arg) const
		{
			return !(*this == arg);
		}
		template <typename U>
		Vector3<T> operator* (const U & arg) const
		{
			return Vector3<T>(x*arg, y*arg, z*arg);
		}
		template <typename U>
		Vector3<T> & operator*= (const U & arg)
		{
			x = x*arg;
			y = y*arg;
			z = z*arg;
			return *this;
		}
		template <typename U>
		Vector3<T> operator/ (const U & arg) const
		{
			//Assert(arg != 0);
			U inv = 1.0/arg;
			return Vector3<T>(x * inv, y * inv, z * inv);
		}
		template <typename U>
		Vector3<T> & operator/= (const U & arg)
		{
			//Assert(arg != 0);
			U inv = 1.0/arg;
			x = x * inv;
			y = y * inv;
			z = z * inv;
			return *this;
		}
		Vector3<T> operator- () const
		{
			return Vector3<T>(-x, -y, -z);
		}
		T operator[] (int i) const
		{
			Assert(i == 0 || i == 1 || i == 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		T & operator[] (int i)
		{
			Assert(i == 0 || i == 1 || i == 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}

		//member function
		double length() const
		{
			return std::sqrt(x*x + y*y + z*z);
		}
		double length2() const
		{
			return x*x+y*y+z*z;
		}

		//friend function
		template <typename U>
		friend Vector3<T> operator* (U t, const Vector3<T> & arg)
		{
			return Vector3<T>(t*arg.x, t*arg.y, t*arg.z);
		}
		friend std::ostream & operator<< (std::ostream & os,const Vector3 & v)
		{
			os<<"(v3:"<<v.x<<","<<v.y<<","<<v.z<<")";
			return os;
		}

		//Public data member
		T x, y, z;
	private:
	};

	template <typename T>
	inline T dot(const Vector2<T> & lhs, const Vector2<T> & rhs)
	{
		return lhs.x*rhs.x + lhs.y*rhs.y;
	}
	template <typename T>
	inline T dot(const Vector3<T> & lhs, const Vector3<T> & rhs)
	{
		return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
	}
	template <typename T>
	inline T absDot(const Vector2<T> & lhs, const Vector2<T> & rhs)
	{
		return std::abs(lhs.x*rhs.x + lhs.y*rhs.y);
	}
	template <typename T>
	inline T absDot(const Vector3<T> & lhs, const Vector3<T> & rhs)
	{
		return std::abs(lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z);
	}

	template <typename T>
	inline Vector3<T> cross(const Vector3<T> & lhs, const Vector3<T> & rhs)
	{
		T   x = lhs.y*rhs.z - lhs.z*rhs.y,
			y = lhs.z*rhs.x - lhs.x*rhs.z,
			z = lhs.x*rhs.y - lhs.y*rhs.x;
		return Vector3<T>(x, y, z);
	}

	template <typename T>
	inline Vector3<T> normalize(const Vector3<T> & arg)
	{
		if (arg.length2() == 0)
			return arg;
		return arg / arg.length();
	}

	template <typename T>
	inline Vector3<T> mult (const Vector3<T> & lhs,const Vector3<T> & rhs)
	{
		return Vector3<T> (lhs.x*rhs.x,lhs.y*rhs.y,lhs.z*rhs.z);
	}

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<float> Spectrum;

	template <typename T>
	class Normal3
	{
	public:
		Normal3 ():Normal3(0,1,0)
		{}
		Normal3 (T xx,T yy,T zz):x(xx),y(yy),z(zz)
		{}
		Normal3 (const Normal3<T> & n):x(n.x),y(n.y),z(n.z)
		{}
		explicit Normal3 (const Vector3<T> & v):x(v.x),y(v.y),z(v.z)
		{}

		//Operator
		Normal3<T> operator+ (const Normal3 & arg) const
		{
			return Normal3<T> (x+arg.x,y+arg.y,z+arg.z);
		}
		Normal3<T> & operator+= (const Normal3 & arg)
		{
			x = x+arg.x;
			y = y+arg.y;
			z = z+arg.z;
			return *this;
		}
		Normal3<T> operator- (const Normal3 & arg) const
		{
			return Normal3<T> (x-arg.x,y-arg.y,z-arg.z);
		}
		Normal3<T> & operator-= (const Normal3 & arg)
		{
			x = x-arg.x;
			y = y-arg.y;
			z = z-arg.z;
			return *this;
		}
		template <typename U>
		Normal3<T> operator* (const U & s) const
		{
			return Normal3<T> (x*s,y*s,z*s);
		}
		template <typename U>
		Normal3<T> & operator*= (const U & s)
		{
			x = x*s;
			y = y*s;
			z = z*s;
			return *this;
		}
		template <typename U>
		Normal3<T> operator/ (const U & s) const
		{
			//Assert (s!=0);
			U inv = 1.0/s;
			return Normal3<T> (x*inv,y*inv,z*inv);
		}
		template <typename U>
		Normal3<T> & operator/= (const U & s)
		{
			//Assert (s!=0);
			U inv = 1.0/s;
			x = x*inv;
			y = y*inv;
			z = z*inv;
			return *this;
		}

		double length() const
		{
			return std::sqrt(x*x+y*y+z*z);
		}
		double length2() const
		{
			return x*x+y*y+z*z;
		}
		friend std::ostream & operator<<(std::ostream & os,const Normal3<T> & n)
		{
			os<<"(n3:"<<n.x<<","<<n.y<<","<<n.z<<")";
			return os;
		}

		//Public data member
		T x,y,z;
	private:
	};

	template <typename T>
	inline Normal3<T> normalize(const Normal3<T> & arg)
	{
		if (arg.length2() == 0)
			return arg;
		return arg / arg.length();
	}

	typedef Normal3<float> Normal3f;

	template <typename T>
	class Matrix4
	{
	public:
		Matrix4 ()
		{
			setToIdentity ();
		}
		Matrix4 (T m00,T m01,T m02,T m03,\
				 T m10,T m11,T m12,T m13,\
				 T m20,T m21,T m22,T m23,\
				 T m30,T m31,T m32,T m33)/*:\
			_m({m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33})*/
		{(*this)(0,0)=m00;(*this)(0,1)=m01;(*this)(0,2)=m02;(*this)(0,3)=m03;
		 (*this)(1,0)=m10;(*this)(1,1)=m11;(*this)(1,2)=m12;(*this)(1,3)=m13;
		 (*this)(2,0)=m20;(*this)(2,1)=m21;(*this)(2,2)=m22;(*this)(2,3)=m23;
		 (*this)(3,0)=m30;(*this)(3,1)=m31;(*this)(3,2)=m32;(*this)(3,3)=m33;}

		//Operator
		inline T & operator() (int row,int column)
		{
			return _m[row*4+column];
		}
		inline T operator() (int row,int column) const
		{
			return _m[row*4+column];
		}
		inline const T * operator[](int row) const
		{
			return &_m[4*row];
		}
		inline T * operator[](int row)
		{
			return &_m[4*row];
		}
		bool operator==(const Matrix4 & mat) const
		{
			for (int i=0;i<16;++i)
				if (_m[i] != mat._m[i])
					return false;
			return true;
		}
		bool operator!=(const Matrix4 & mat) const
		{
			return !(*this == mat);
		}
		Matrix4 operator+(const Matrix4 & mat) const
		{
			Matrix4 res;
			for (int i=0;i<16;++i)
				res._m[i] = _m[i] + mat._m[i];
			return res;
		}
		Matrix4 operator-(const Matrix4 & mat) const
		{
			Matrix4 res;
			for (int i=0;i<16;++i)
				res._m[i] = _m[i] - mat._m[i];
			return res;
		}
		Matrix4 operator*(const Matrix4 & mat) const
		{
			Matrix4 res;
			for (int row=0;row<4;++row)
				for (int column=0;column<4;++column)
					res(row,column) = (*this)(row,0)*mat(0,column) + (*this)(row,1)*mat(1,column) + \
									  (*this)(row,2)*mat(2,column) + (*this)(row,3)*mat(3,column);
			return res;
		}
		Matrix4 operator*(T s) const
		{
			Matrix4 res;
			for (int i=0;i<16;++i)
				res._m[i] = _m[i] * s;
			return res;
		}
		Matrix4 operator/(T s) const
		{
			Matrix4 res;
			Assert (s!=0);
			T inv = 1.0/s;
			for (int i=0;i<16;++i)
				res._m[i] = _m[i] * inv;
			return res;
		}
		Matrix4 & operator+=(const Matrix4 & mat)
		{
			for (int i=0;i<16;++i)
				_m[i] += mat._m[i];
			return (*this);
		}
		Matrix4 & operator-=(const Matrix4 & mat)
		{
			for (int i=0;i<16;++i)
				_m[i] -= mat._m[i];
			return (*this);
		}
		Matrix4 & operator*=(const Matrix4 & mat)
		{
			*this = (*this) * mat;
			return *this;
		}
		Matrix4 & operator*=(T s)
		{
			for (int i=0;i<16;++i)
				_m[i] = _m[i] * s;
			return *this;
		}
		Matrix4 & operator/=(T s)
		{
			Assert(s!=0);
			T inv = 1.0/s;
			for (int i=0;i<16;++i)
				_m[i] = _m[i] * inv;
			return *this;
		}
		//Multiple vector,point,normal
		//Matrix multiple ray are define in ray.h
		Vector3<T> operator* (const Vector3<T> & ve) const
		{
			T xp = _m[0]*ve.x + _m[1]*ve.y + _m[2]*ve.z;
			T yp = _m[4]*ve.x + _m[5]*ve.y + _m[6]*ve.z;
			T zp = _m[8]*ve.x + _m[9]*ve.y + _m[10]*ve.z;
			return Vector3<T> (xp,yp,zp);
		}

		Point3<T> operator* (const Point3<T> & p) const
		{
			T xp = _m[0]*p.x + _m[1]*p.y + _m[2]*p.z + _m[3];
			T yp = _m[4]*p.x + _m[5]*p.y + _m[6]*p.z + _m[7];
			T zp = _m[8]*p.x + _m[9]*p.y + _m[10]*p.z + _m[11];
			T wp = _m[12]*p.x + _m[13]*p.y + _m[14]*p.z + _m[15];
			if (wp == 1)
			{
				return Point3<T> (xp,yp,zp);
			}
			else
			{
				T inv = 1.0/wp;
				return Point3<T> (xp*inv,yp*inv,zp*inv);
			}
		}

		Normal3<T> operator* (const Normal3<T> & n) const
		{Assert(0);}

		//Member function
		Matrix4 inverse () const
		{
			Matrix4 inv;
			float det;
			inv._m[0] = _m[5] * _m[10] * _m[15]
				- _m[5]  * _m[11] * _m[14]
				- _m[9]  * _m[6]  * _m[15]
				+ _m[9]  * _m[7]  * _m[14]
				+ _m[13] * _m[6]  * _m[11]
				- _m[13] * _m[7]  * _m[10];

			inv._m[4] = -_m[4]  * _m[10] * _m[15]
				+ _m[4]  * _m[11] * _m[14]
				+ _m[8]  * _m[6]  * _m[15]
				- _m[8]  * _m[7]  * _m[14]
				- _m[12] * _m[6]  * _m[11]
				+ _m[12] * _m[7]  * _m[10];

			inv._m[8] = _m[4]  * _m[9] * _m[15]
				- _m[4]  * _m[11] * _m[13]
				- _m[8]  * _m[5] * _m[15]
				+ _m[8]  * _m[7] * _m[13]
				+ _m[12] * _m[5] * _m[11]
				- _m[12] * _m[7] * _m[9];

			inv._m[12] = -_m[4]  * _m[9] * _m[14]
				+ _m[4]  * _m[10] * _m[13]
				+ _m[8]  * _m[5] * _m[14]
				- _m[8]  * _m[6] * _m[13]
				- _m[12] * _m[5] * _m[10]
				+ _m[12] * _m[6] * _m[9];

			inv._m[1] = -_m[1]  * _m[10] * _m[15]
				+ _m[1]  * _m[11] * _m[14]
				+ _m[9]  * _m[2] * _m[15]
				- _m[9]  * _m[3] * _m[14]
				- _m[13] * _m[2] * _m[11]
				+ _m[13] * _m[3] * _m[10];

			inv._m[5] = _m[0]  * _m[10] * _m[15]
				- _m[0]  * _m[11] * _m[14]
				- _m[8]  * _m[2] * _m[15]
				+ _m[8]  * _m[3] * _m[14]
				+ _m[12] * _m[2] * _m[11]
				- _m[12] * _m[3] * _m[10];

			inv._m[9] = -_m[0]  * _m[9] * _m[15]
				+ _m[0]  * _m[11] * _m[13]
				+ _m[8]  * _m[1] * _m[15]
				- _m[8]  * _m[3] * _m[13]
				- _m[12] * _m[1] * _m[11]
				+ _m[12] * _m[3] * _m[9];

			inv._m[13] = _m[0]  * _m[9] * _m[14]
				- _m[0]  * _m[10] * _m[13]
				- _m[8]  * _m[1] * _m[14]
				+ _m[8]  * _m[2] * _m[13]
				+ _m[12] * _m[1] * _m[10]
				- _m[12] * _m[2] * _m[9];

			inv._m[2] = _m[1]  * _m[6] * _m[15]
				- _m[1]  * _m[7] * _m[14]
				- _m[5]  * _m[2] * _m[15]
				+ _m[5]  * _m[3] * _m[14]
				+ _m[13] * _m[2] * _m[7]
				- _m[13] * _m[3] * _m[6];

			inv._m[6] = -_m[0]  * _m[6] * _m[15]
				+ _m[0]  * _m[7] * _m[14]
				+ _m[4]  * _m[2] * _m[15]
				- _m[4]  * _m[3] * _m[14]
				- _m[12] * _m[2] * _m[7]
				+ _m[12] * _m[3] * _m[6];

			inv._m[10] = _m[0]  * _m[5] * _m[15]
				- _m[0]  * _m[7] * _m[13]
				- _m[4]  * _m[1] * _m[15]
				+ _m[4]  * _m[3] * _m[13]
				+ _m[12] * _m[1] * _m[7]
				- _m[12] * _m[3] * _m[5];

			inv._m[14] = -_m[0]  * _m[5] * _m[14]
				+ _m[0]  * _m[6] * _m[13]
				+ _m[4]  * _m[1] * _m[14]
				- _m[4]  * _m[2] * _m[13]
				- _m[12] * _m[1] * _m[6]
				+ _m[12] * _m[2] * _m[5];

			inv._m[3] = -_m[1] * _m[6] * _m[11]
				+ _m[1] * _m[7] * _m[10]
				+ _m[5] * _m[2] * _m[11]
				- _m[5] * _m[3] * _m[10]
				- _m[9] * _m[2] * _m[7]
				+ _m[9] * _m[3] * _m[6];

			inv._m[7] = _m[0] * _m[6] * _m[11]
				- _m[0] * _m[7] * _m[10]
				- _m[4] * _m[2] * _m[11]
				+ _m[4] * _m[3] * _m[10]
				+ _m[8] * _m[2] * _m[7]
				- _m[8] * _m[3] * _m[6];

			inv._m[11] = -_m[0] * _m[5] * _m[11]
				+ _m[0] * _m[7] * _m[9]
				+ _m[4] * _m[1] * _m[11]
				- _m[4] * _m[3] * _m[9]
				- _m[8] * _m[1] * _m[7]
				+ _m[8] * _m[3] * _m[5];

			inv._m[15] = _m[0] * _m[5] * _m[10]
				- _m[0] * _m[6] * _m[9]
				- _m[4] * _m[1] * _m[10]
				+ _m[4] * _m[2] * _m[9]
				+ _m[8] * _m[1] * _m[6]
				- _m[8] * _m[2] * _m[5];

			det = _m[0] * inv._m[0] + _m[1] * inv._m[4]
				+ _m[2] * inv._m[8] + _m[3] * inv._m[12];
			Assert(det != 0);
			det = 1.0 / det;

			for (size_t i = 0; i < 16; ++i){
				inv._m[i] *= det;
			}
			return inv;
		}
		Matrix4 transpose () const
		{
			Matrix4 res;
			for (int row=0;row<4;++row)
				for (int column=0;column<4;++column)
					res(row,column) = (*this)(column,row);
			return res;
		}
		Matrix4 & setToIdentity ()
		{
			for (int row=0;row<4;++row)
				for (int column=0;column<4;++column)
					(*this)(row,column) = (row==column ? 1:0);
			return *this;
		}

		friend std::ostream & operator<< (std::ostream & os,const Matrix4 & mat)
		{
			os << "(m:";
			for (int row = 0; row < 4; ++row){
				os << "["<<row<<" : ";
				for (int column = 0; column < 4; ++column){
					os << mat(row,column);
					os << (column==3 ? ' ':',');
				}
				os << "] ";
			}
			os<<")";
			return os;
		}
	private:
		T _m [16];
	};

	typedef Matrix4<float> Matrix4f;

	Matrix4f translate (const Vector3f & ve);
	Matrix4f scale (float x,float y,float z);
	//Define with degree , not radian
	Matrix4f rotateX (float degree);
	Matrix4f rotateY (float degree);
	Matrix4f rotateZ (float degree);
	Matrix4f rotate (const Vector3f & axis,float degree);
	Matrix4f orthographic (float near,float far);
	Matrix4f perspective (float fov,float near,float far);
	//Camera to world
	Matrix4f lookAt (const Point3f & pos,const Point3f & at,const Vector3f & up);

	//Util
	template <typename T>
	inline T clamp(T t, T lft, T rht)
	{
		if (t < lft)        return lft;
		else if (t > rht)   return rht;
		else                return t;
	}

	template <typename T>
	inline T lerp(T lhs, T rhs, float t)
	{
	    Assert(t>=0 && t<=1);
		return lhs*(1-t)+rhs*t;
	}

	void coordinateSystem (const Vector3f & v1,Vector3f & v2,Vector3f & v3);
	template <typename T>
	inline T radians (T degree)
	{
        return degree*180.0/PI;
	}
}
