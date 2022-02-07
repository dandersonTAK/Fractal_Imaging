#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace passionproj {

	class Mandelbrot {
	public:
		Mandelbrot();

		static const int MAX_ITERATIONS = 1000; //more iterations means a better quality pic, but it'll take more processing power

		static int getIterations(double x, double y);
	}; //class end Mandelbrot

} //end namespace

#endif MANDELBROT_H_