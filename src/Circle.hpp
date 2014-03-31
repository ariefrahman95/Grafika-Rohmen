#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle {
	public:
		// ctor-dtor-cctor
		Circle();
		Circle(Point, double, int);
		~Circle();
		Circle(const Circle&);
		Circle& operator=(const Circle&);
		
		//method
		void Translate(double, double);
		void Scale(double, const Point);
		void Rotate(double, const Point);
	
		Point C;
		double R;
		int color;
};

#endif