#include "FractalCreator.h"
#include <iostream>

namespace passionproj{

	FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height),
		//I don't want pixels in m_histogram that have value MAX_ITERATIONS b/c it'll mess up the color scaling. If I did want those values, the array would be size MAX_ITERATIONS+1
		m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }),
		m_fractal(new int[m_width * m_height]{ 0 }),
		m_bitty(m_width, m_height),
		m_zoomList(m_width, m_height)
	{
		m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
	}

	void FractalCreator::calculateIteration() {
		for (int x = 0; x < m_width; x++) {
			for (int y = 0; y < m_height; y++) {
				pair<double, double> coords = m_zoomList.doZoom(x, y);

				int iterations = Mandelbrot::getIterations(coords.first, coords.second); //static function

				m_fractal[y * m_width + x] = iterations; //0x0 is the bottom left pixel. I'll read the screen left to right, bottom to top

				if (iterations != Mandelbrot::MAX_ITERATIONS) { //I don't want pixels that equal MAX_ITERATIONS
					m_histogram[iterations]++;
				}

			}
		}
	}

	void FractalCreator::drawFractal() {
		
		int totalPixels{ 0 };

		for (int x = 0; x < m_width; x++) {
			for (int y = 0; y < m_height; y++) {
				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;

				int iterations_scale = m_fractal[y * m_width + x];

				int range = getRange(iterations_scale);
				int rangeTotal = m_rangeTotals[range]; //retrieving how many pixels total are in this range
				int rangeStart = m_ranges[range]; //Number of iterations at the start of the range 
				
				RGB& startColor = m_colors[range];
				RGB& endColor = m_colors[range+1];
				RGB colorDiff = endColor - startColor;

				//Don't change the color or hue for pixels that hit MAX_ITERATIONS. Let them be black.
				if (iterations_scale != Mandelbrot::MAX_ITERATIONS) {

					totalPixels = 0;
					
					//Pixels that share an iteration count with other pixels will have a brighter hue
					for (int h = rangeStart; h <= iterations_scale; h++) {
						totalPixels += m_histogram[h];
					}

					red = startColor.m_r + colorDiff.m_r*(double)totalPixels/rangeTotal; //tP/rT will give a number btwn 0 and 1
					green = startColor.m_g + colorDiff.m_g * (double)totalPixels / rangeTotal;
					blue = startColor.m_b + colorDiff.m_b * (double)totalPixels / rangeTotal;

				}

				m_bitty.setPixel(x, y, red, green, blue);

			}
		}
	}

	void FractalCreator::calculateTotalIterations() {
		for (int q = 0; q < Mandelbrot::MAX_ITERATIONS; q++) {
			m_total += m_histogram[q];
		}

	}

	void FractalCreator::calculateRangeTotals() {

		int rangeIndex = 0;

		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			int pixels = m_histogram[i]; //for each iteration, returns the number of pixels in that iteration

			if (i >= m_ranges[rangeIndex + 1]) {
				rangeIndex++;
			}
		
			m_rangeTotals[rangeIndex] += pixels;
		}

	}

	void FractalCreator::addColorRange(double rangeEnd, const RGB& rgb) {
		m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
		m_colors.push_back(rgb);

		if (m_bGotFirstRange) { //skip the first added range ending in 0.0
			m_rangeTotals.push_back(0); //initialize each range after that to 0
		}

		m_bGotFirstRange = true;
	}

	void FractalCreator::addZoom(const Zoom& zoom) {
		m_zoomList.add(zoom);
	}

	void FractalCreator::writeBitmap(string name) {
		m_bitty.write(name);
	}


	void FractalCreator::run(string name) {
		calculateIteration();
		calculateTotalIterations();
		calculateRangeTotals();
		drawFractal();
		writeBitmap("test.bmp");
	}

	int FractalCreator::getRange(int iterations) const {
		int range = 0;

		//It's easier to visualize the ranges starting from 1 and then subtract 1 after the loop
		for (int i = 1; i < m_ranges.size(); i++) { 
			range = i;

			if (m_ranges[i] > iterations) {
				break;
			}
		}

		range--;

		//Just to be sure that my range is OK. C++ will let me read junk values outside of a vector's index.
		assert(range > -1);
		assert(range < m_ranges.size());

		return range;
	}
} //end namespace