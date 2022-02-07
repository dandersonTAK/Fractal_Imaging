#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint> //Gives me int32_t and int16_t

using namespace std;

//Remove padding so the bitmap is readable
#pragma pack(push, 2)

//Good habit to make a custom namespace for each project
namespace passionproj {

	struct BitmapInfoHeader {
		int32_t headerSize{ 40 }; //Size of this struct
		int32_t width; //of the bitmap
		int32_t height; //of the bitmap
		int16_t planes{ 1 }; //layer feature of the bitmap
		int16_t bitsPerPixel{ 24 }; //1 byte per color, each pixel has RGB, 1 byte = 8 bits, thus 24 bits per pixel
		int32_t compression{ 0 }; //No compression
		int32_t dataSize{ 0 }; //Will be changed later when we know the data size 
		int32_t horizontalResolution{ 2400 }; //bits per pixel
		int32_t verticalResolution{ 2400 }; //bits per pixel
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };
	};

}

#pragma pack(pop)

#endif
