#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include <cassert>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace passionproj {

	class FractalCreator {
	private:
		int m_width{0};
		int m_height{0};
		unique_ptr<int[]> m_histogram; //stores the number of pixels that have X number of iterations. 
		unique_ptr<int[]> m_fractal; //storing number of iterations per pixel
		Bitmap m_bitty;
		ZoomList m_zoomList;
		int m_total{ 0 };
		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals; //holds how big each range is in pixels
		bool m_bGotFirstRange{ false }; //makes sure I don't compare the first range ending at 0 to 0. Doubles aren't precise, so it could have consequences.

		void calculateIteration();
		void drawFractal();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void writeBitmap(string name);
		int getRange(int iterations) const; //ensuring my pixels are in the correct range
		

	public:
		FractalCreator(int width, int height); 
		//addColorRange lets you say what colors should be present in the iteration range of (previous rangeEnd) through rangeEnd
		void addColorRange(double rangeEnd, const RGB& rgb);
		void addZoom(const Zoom& zoom);
		void run(string name);		
	};
} //end namespace passionproj


#endif //FRACTALCREATOR_H_