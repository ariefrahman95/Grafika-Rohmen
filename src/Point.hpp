#ifndef POINT_HPP
#define POINT_HPP

// point data structure
class Point {
	
	public:
		// 4 sekawan
		Point();
		Point(double, double);
		~Point();
		Point(const Point&);
		Point& operator=(const Point&);
		
		// additional method(s)
		void swap(); // swap x by y and vice versa
		
		// attributes (they're in public for easy access)
		double x;
		double y;
};

#endif