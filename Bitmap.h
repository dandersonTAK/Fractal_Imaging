#pragma once
#include <string>
#include <cstdint> //for uint8_t
#include <memory>
#include <iostream>

using namespace std;

namespace passionproj {

class Bitmap {
private:
	int m_width{0}; //m for member
	int m_height{0}; //I don't like starting a var with _
	unique_ptr<uint8_t[]> m_pPixels{nullptr}; //using unique_ptr so deletion of the array is handled for me

public:
	Bitmap(int width, int height);
	bool write(string filename);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); //uint8_t is like an unsigned char, values go from 0-255, which is what I want for RGB values
	virtual ~Bitmap(); //virtual destructor
}; //class end Bitmap

} //end namespace