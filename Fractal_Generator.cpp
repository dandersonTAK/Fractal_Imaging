//============================================================================
// Name        : Fractal_Generator.cpp
// Author      : Dane Anderson
// Version     : 2.0
// Description : Hello World in C++, make sure my IDE is ready.
//				 The fractal images are based on the Mandelbrot computer-generated fractal images.
//============================================================================

#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace passionproj;

//I like to keep the main method simple. Most of the logic happens in function calls done by run().
int main() {

	FractalCreator fractalCreator(800, 600); //width by height, values are fstandard min screen resolution

	//In case you want to play with the colors, most pixels are in the range from 0.0 to 0.1
	//lines 24 and 25 define the color range from iterations = 0 to iterations = Mandelbrot::MAX_ITERATIONS/3.
	fractalCreator.addColorRange(0.0, RGB(0, 0, 0));
	fractalCreator.addColorRange(0.05, RGB(185, 255, 105));
	fractalCreator.addColorRange(0.1, RGB(255, 0, 0));
	fractalCreator.addColorRange(0.8, RGB(0, 0, 255));
	fractalCreator.addColorRange(1.0, RGB(255, 255, 255));

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.addZoom(Zoom(330, 440, 0.1));
	fractalCreator.run("test.bmp");

	cout << "The fractal is done generating." << endl; 
	return 0;
}
