#include "Point.hpp"

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

Point::~Point() {}

Point::Point(const Point& P) {
	x = P.x;
	y = P.y;
}

Point& Point::operator=(const Point& P) {
	x = P.x;
	y = P.y;
	return *this;
}

Point& Point::operator+=(const Point& P) {
	x += P.x;
	y += P.y;
	return *this;
}

Point& Point::operator-=(const Point& P) {
	x -= P.x;
	y -= P.y;
	return *this;
}

Point& Point::operator*=(const double k) {
	x *= k;
	y *= k;
	return *this;
}

// swap x-y or y-x
void Point::Swap() {
	int t = x;
	x = y;
	y = t;
}