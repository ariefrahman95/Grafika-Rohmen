#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Stroke.hpp"

class Circle: public Stroke {
	public:
		// ctor-dtor-cctor
		Circle();
		Circle(Point, double);
		~Circle();
		Circle(const Circle&);
		Circle& operator=(const Circle&);
		
		//method
		void draw();
		void translate(double, double);
		void scale(double, Point);
		void rotate(double,Point);
		void reflect(double, Point);
		void shear(double, double, Point);
		
	private:
		Point center_point;
		double radius;
		int color;
};
#endif