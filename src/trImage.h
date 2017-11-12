#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>

#include "trPrerequisite.h"
#include "trColor.h"

namespace tr
{
	class Image
	{
	public:
		Image (int w=1280,int h=720,const std::string & fn=std::string("output")):_width(w),_height(h),_fileName(fn)
		{
			Assert(_width>0 && _height>0);
			_m = new Color [_width*_height];
		}

		~Image ()
		{
			if (_m != nullptr)
			{
				delete [] _m;
				_m=nullptr;
			}
		}

		inline Color & operator() (int x,int y)
		{
			Assert(x>=0 && x<_width && y>=0 && y<_height);
			return _m[y*_width+x];
		}
		inline Color operator() (int x,int y) const
		{
			Assert(x>=0 && x<_width && y>=0 && y<_height);
			return _m[y*_width+x];
		}

		virtual void saveImage () const = 0;
		//bool readImage ();

		int width() const
		{return _width;}
		int height() const
		{return _height;}

	protected:
		int _width;
		int _height;
		std::string _fileName;
		Color * _m;
	private:
	};

	class PPM : public Image
	{
	public:
	    PPM (int w,int h,const std::string & s):Image(w,h,s)
	    {}

		void saveImage () const override;
	private:
	};

	class BMP : public Image
	{
	public:
	    BMP (int w,int h,const std::string & s):Image(w,h,s)
	    {}

#pragma pack(push)
#pragma pack(2)

	struct BMPFILEHEADER
	{
		uint16_t bfType;
		uint32_t bfSize;
		uint16_t bfReserved1;
		uint16_t bfReserved2;
		uint32_t bfOffBits;
	};

	struct BMPINFOHEADER
	{
		uint32_t biSize;
        uint32_t biWidth;
        uint32_t biHeight;
		uint16_t biPlanes;
		uint16_t biBitCount;
		uint32_t biCompression;
		uint32_t biSizeImage;
        uint32_t biXPelsPerMeter;
		uint32_t biYPelsPerMeter;
		uint32_t biClrUsed;
		uint32_t biClrImportant;
	};
#pragma pack(pop)

		void saveImage () const override;
	private:
	};
}
