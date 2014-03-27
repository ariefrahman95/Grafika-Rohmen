#ifndef STROKE_HPP
#define STROKE_HPP

#include "Point.hpp"

//abstract class utk Stroke&line
class Stroke {
	public:
		// ctor-dtor
		Stroke();
		~Stroke();
		Stroke(const Stroke&);
		Stroke& operator=(const Stroke&);
		
		//virtual method
		virtual void draw() = 0;
		virtual void translate(double, double) = 0;
		virtual void scale(double, Point) = 0;
		virtual void rotate(double,Point) = 0;
		virtual void reflect(double, Point) = 0;
		virtual void shear(double, double, Point) = 0;
	
	protected:
		int color;
};
#endif