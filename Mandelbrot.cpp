//Complex numbers make the Mandelbrot alg implementation easier
#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace passionproj {
	Mandelbrot::Mandelbrot() {
		//TODO
	}

	int Mandelbrot::getIterations(double x, double y){ //x and y depends on what pixel we're working on

		complex<double> z = 0; //sets both numbers that make up the complex number to 0
		complex<double> c(x, y); //the pair of numbers is initialized as x and y. 

		int iterations = 0;

		//If the magnitude never exceeds 2, the complex num is in the Mandelbrot set. 
		//If the magnitude does exceed 2, that means it's tending towards infinity, and I need to stop it then and there.
		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;
			
			if (abs(z) > 2) { //getting the magnitude of this complex number
				break;
			}

			iterations++;
		}

		return iterations; //Iterations will either equal MAX_ITERATIONS or show where the magnitude exceeded 2
	}

} //end namespace