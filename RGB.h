#ifndef RGB_H_
#define RGB_H_

namespace passionproj {

	struct RGB {
	
		double m_r;
		double m_g;
		double m_b;
	
		RGB(double r, double g, double b);
		
	};

	RGB operator-(const RGB& first, const RGB& second);

} //end namespace



#endif //RGB_H_