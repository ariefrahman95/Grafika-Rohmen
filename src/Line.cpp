#include "Line.hpp"
#include <math.h>

Line::Line(){
	P0 = Point();
	P1 = Point();
	color = 0;
}

Line::Line(Point P0, Point P1, int C){
	this->P0 = P0;
	this->P1 = P1;
	color = C; //warna
}

Line::~Line(){
}

Line::Line(const Line& L){
	P0 = L.P0;
	P1 = L.P1;
	color = L.color;
}

Line& Line::operator=(const Line& L){
	P0 = L.P0;
	P1 = L.P1;
	color = L.color;
	return *this;
}

void Line::Translate(double dx, double dy){ //dx = perpindahan titik x, dy = perpindahan titik y
	const Point P = Point(dx,dy);
	P0 += P;
	P1 += P;
}

void Line::Scale(double sc, const Point P){ //sc = skala, P = titik pusat skala
	P0 -= P;
	P1 -= P;
	
	P0 *= sc;
	P1 *= sc;
	
	P0 += P;
	P1 += P;
}

void Line::Rotate(double angle, const Point P){ //angle = derajat putaran (dalam derajat), P = titik pusat rotasi
	P0 -= P;
	P1 -= P;
	
	double s = sin(angle * 3.14159265/180);
	double c = cos(angle * 3.14159265/180);
	
	P0.x = P0.x * c - P0.y * s;
	P0.y = P0.x * s + P0.y * c;
	
	P1.x = P1.x * c - P1.y * s;
	P1.y = P1.x * s + P1.y * c;
	
	P0 += P;
	P1 += P;
}
