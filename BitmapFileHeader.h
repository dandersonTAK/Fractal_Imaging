//BitmapFileHeader.h

#ifndef BITMAPFILEHEADER_H_ //If this string isn't defined, then defined it as below
#define BITMAPFILEHEADER_H_ //Here's the definition

#include <cstdint> //Ensures int is 32 bit

using namespace std;

//The below pragma makes sure that the struct data is packed with 2 byte boundaries and not with normal padding
//I don't want padding b/c I want the struct to be written exactly as I define it here. 
//The padding would make the bitmap unreadable. No fluff.
#pragma pack(push, 2)

//Good habit to make a custom namespace for each project
namespace passionproj {

	//Members of a struct are public by default. Members of a class are private by default. 
	struct BitmapFileHeader {
		char header[2]{ 'B','M' };
		int32_t fileSize; //size of the bitmap file. Ensuring int is 32 bit. Writing to the file is picky, so I'm ensuring the input is the correct format
		int32_t reserved{ 0 };
		int32_t dataOffset; //Set later. Says how far into the file the data actually begins
	};

}

#pragma pack(pop)

#endif /* BITMAPFILEHEADER_H_ */   //End of the if statement 
