#ifndef ZOOM_H_
#define ZOOM_H_

namespace passionproj {

	//A struct which lets us zoom on certain pixels
	struct Zoom {
		//The coordinates I want to zoom in on
		int m_x{0};
		int m_y{0};

		double m_scale{0.0};
		Zoom(int x, int y, double scale) : m_x(x), m_y(y), m_scale(scale) {};
	}; //struct end Zoom

} //end namespace

#endif //ZOOM_H_