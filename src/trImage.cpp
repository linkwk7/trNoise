#include "trImage.h"

namespace tr
{
	void PPM::saveImage () const
	{
		std::fstream file (_fileName+std::string(".ppm"),std::fstream::out|std::fstream::binary);
		Assert(file.is_open());
		file<<"P6\n"<<_width<<" "<<_height<<"\n255\n";
		for (int i=_height-1,counter=0;i>=0;--i)
		{
			for (int j=0;j<_width;++j,++counter)
			{
				Color & clr (_m[counter]);
				unsigned char r = static_cast<unsigned char> (clr.r*255),
							  g = static_cast<unsigned char> (clr.g*255),
							  b = static_cast<unsigned char> (clr.b*255);
				file<<r<<g<<b;
			}
		}
		file.close();
	}

	void BMP::saveImage () const
	{
		std::ofstream file(_fileName+std::string(".bmp"), std::fstream::out|std::fstream::binary);
		Assert(file.is_open());

		BMPFILEHEADER fileHeader;
		BMPINFOHEADER infoHeader;

		std::memset(&fileHeader, 0, sizeof(BMPFILEHEADER));
        std::memset(&infoHeader, 0, sizeof(BMPINFOHEADER));
        fileHeader.bfType = 0x4d42;
		fileHeader.bfSize = sizeof(BMPFILEHEADER) + sizeof(BMPINFOHEADER) + _width*_height * 4;
		fileHeader.bfReserved1 = 0;
		fileHeader.bfReserved2 = 0;
		fileHeader.bfOffBits = sizeof(BMPFILEHEADER) + sizeof(BMPINFOHEADER);
		infoHeader.biSize = sizeof(BMPINFOHEADER);
		infoHeader.biWidth = _width;
		infoHeader.biHeight = _height;
		infoHeader.biPlanes = 1;
		infoHeader.biBitCount = 32;
		infoHeader.biCompression = 0L;
		infoHeader.biSizeImage = _width*_height * 4;
		infoHeader.biXPelsPerMeter = 0;
		infoHeader.biYPelsPerMeter = 0;
		infoHeader.biClrUsed = 0;
		infoHeader.biClrImportant = 0;
		file.write(reinterpret_cast<char*>(&fileHeader), sizeof(BMPFILEHEADER));
		file.write(reinterpret_cast<char*>(&infoHeader), sizeof(BMPINFOHEADER));
		for (int y=0;y<_height;++y)
        {
            for (int x=0;x<_width;++x)
            {
                Color clr = _m[x+(_height-1-y)*_width].clamp();
                unsigned char buf [4];
                std::memset(buf,0,sizeof(buf));
                buf[0] = static_cast<unsigned char>(clr.b*255);
				buf[1] = static_cast<unsigned char>(clr.g*255);
				buf[2] = static_cast<unsigned char>(clr.r*255);
				buf[3] = static_cast<unsigned char>(255);
				file.write(reinterpret_cast<char*>(buf),sizeof(buf));
            }
        }

		file.close();
	}
}
