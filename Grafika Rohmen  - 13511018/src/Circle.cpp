#include "Circle.hpp"
#include <math.h>

Circle::Circle() {
	R = 100;
	color = 0;
}

Circle::Circle(Point C, double r, int color) {
	this->C = C;
	this->R = r;
	this->color = color;
}

Circle::~Circle() {}

Circle::Circle(const Circle& Circ) {
	C = Circ.C;
	R = Circ.R;
	color = Circ.color;
}

Circle& Circle::operator=(const Circle& Circ) {
	C = Circ.C;
	R = Circ.R;
	color = Circ.color;
	return *this;
}

void Circle::Translate(double dx, double dy){ //dx = perpindahan titik x, dy = perpindahan titik y
	const Point P = Point(dx,dy);
	C += P;
}

void Circle::Scale(double sc, const Point P){ //sc = skala, P = titik pusat skala
	C -= P;
	C *= sc;
	C += P;
	
	R *= sc;
}

void Circle::Rotate(double angle, const Point P){ //angle = derajat putaran (dalam derajat), P = titik pusat rotasi
	C -= P;
	
	double s = sin(angle * 3.14159265/180);
	double c = cos(angle * 3.14159265/180);
	
	double x = C.x;
	double y = C.y;
	
	C.x = x * c - y * s;
	C.y = x * s + y * c;
	
	C += P;
}
