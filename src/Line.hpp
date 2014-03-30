#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

class Line {
	public:
		// ctor-dtor-cctor
		Line();
		Line(Point,Point,int);
		~Line();
		Line(const Line&);
		Line& operator=(const Line&);
		
		//method
		void Translate(double, double);
		void Scale(double, const Point);
		void Rotate(double, const Point);
		
		Point P0;
		Point P1;
		int color;
};
#endif