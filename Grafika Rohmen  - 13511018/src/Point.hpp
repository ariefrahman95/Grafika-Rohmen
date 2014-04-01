#ifndef POINT_HPP
#define POINT_HPP

class Point {

	public:
		Point();
		Point(double, double);
		~Point();
		Point(const Point&);
		Point& operator=(const Point&);
		
		Point& operator+=(const Point&);
		Point& operator-=(const Point&);
		Point& operator*=(const double);
		
		// swap x-y or y-x
		void Swap();
		
		// public variables
		double x;
		double y;
};

#endif