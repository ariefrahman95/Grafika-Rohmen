#ifndef LINE_HPP
#define LINE_HPP

#include "Stroke.hpp"
#define CENTERX			( ( getmaxx() + 1 ) / 2 )
#define CENTERY			( ( getmaxy() + 1 ) / 2 )

class Line: public Stroke {
	public:
		// ctor-dtor-cctor
		Line();
		Line(Point,Point,int);
		~Line();
		Line(const Line&);
		Line& operator=(const Line&);
		
		//method
		void draw();
		void translate(double, double);
		void scale(double, Point);
		void rotate(double,Point);
		void reflect(double, Point);
		void shear(double, double, Point);
		
	private:
		Point start_point;
		Point end_point;
		int color;
};
#endif