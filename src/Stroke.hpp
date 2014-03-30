#ifndef STROKE_HPP
#define STROKE_HPP

#include "Point.hpp"

//abstract class utk Stroke&line
class Stroke {
	public:
		//virtual method
		virtual void Translate(double, double) = 0;
		virtual void Scale(double, Point) = 0;
		virtual void Rotate(double,Point) = 0;
};

#endif