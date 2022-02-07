//bitmap.cpp

#include <fstream> //to write to the binary file
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace passionproj; //So I don't have to write passionproj before all of my classes and structs
using namespace std; //I know it's poor practice

namespace passionproj {
	//m_pPixels gets this value b/c each pixel has size 3*uint8_t  b/c of RGB and pixels are present for the size width*height
	//The {0} initializes all of the array mem to 0s
	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{0}) {

	}

	bool Bitmap::write(string filename) {
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		//The fize of the file is the header + info header + data (# of pixels * RGB values)
		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); //After these headers, the data starts

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		ofstream file;

		file.open(filename, ofstream::out | ofstream::binary); //Output filename to stdout and clarify I'm writing a binary file

		if (!file){
			cout << "There was an error opening the file!" << endl;
			return false;
		}//if something goes wrong about opening the file

		file.write((char*)  &fileHeader, sizeof(fileHeader)); //write's first param is a char* ptr, hence my casting. Second param is # of bytes to write
		file.write((char*)  &infoHeader, sizeof(infoHeader)); 
		file.write((char*)  m_pPixels.get(), m_width * m_height * 3); //total pixel size is w*h*3 RGB values
		//I can't cast a unique_ptr to char*. I need a raw ptr to cast, so get() gets me the raw ptr.

		file.close();

		if (!file) {
			cout << "There was an error closing the file!" << endl;
			return false;
		}//if something goes wrong when closing the file

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = m_pPixels.get(); //I can't assign pPixel directly to a unique pointer, but I can point it at the underlying object being pointed to
		//Currently, pPixel points to the bottom left pixel on the whole screen. I want it to point to pixel X by Y

		pPixel += (y*3) * m_width + (x*3); //Each pixel is 3 bytes, so I multiply by 3. y*width brings the pointer to the correct row. x brings it to the correct column

		//Ordered this way b/c bitmaps are little endian order. The least significant byte goes at the smallest address
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	Bitmap::~Bitmap() {

	}
} //end namespace