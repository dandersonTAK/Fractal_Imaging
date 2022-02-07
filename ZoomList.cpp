#include "ZoomList.h"

namespace passionproj {

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {

}

void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);

	//Every zoom shifts the x and y values away from the starting center in the middle of the screen
	m_xCenter += (zoom.m_x - m_width / 2) * m_scale; //Figure out where the cursor is compared to the center of the screen and then scale it so we can zoom multiple times
	m_yCenter += -(zoom.m_y - m_height / 2) * m_scale;

	m_scale *= zoom.m_scale;

}

pair<double, double> ZoomList::doZoom(int x, int y) {
	//move the current center of the screen to the bottom left using m_width/2, then apply scale, then move the center back to where I want by adding m_xCenter
	double xFractal = (x - m_width / 2) * m_scale + m_xCenter; 
	double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

	return pair<double, double>(xFractal, yFractal);
}

} //end namespace