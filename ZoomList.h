#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace passionproj {
	class ZoomList {
	private:
		double m_xCenter{ 0 };
		double m_yCenter{ 0 };
		double m_scale{ 1.0 }; //result of combining all the scales in zooms

		int m_width{ 0 }; //will be assigned the value of screen width
		int m_height{ 0 }; //will be assigned the value of screen height
		vector<Zoom> zooms;

	public:
		ZoomList(int width, int height) ;
		void add(const Zoom& zoom);
		pair<double, double> doZoom(int x, int y);
	}; //class end ZoomList
} //end namespace



#endif //ZOOMLIST_H_