#include "Line.hpp"
#include "transformation.hpp"


Line::Line(){
	start_point = Point();
	end_point = Point();
	color = 0;
}

Line::Line(Point P1, Point P2, int C){
	start_point = P1;
	end_point = P2;
	color = C; //warna
}

Line::~Line(){
}

Line::Line(const Line& L){
	start_point = L.start_point;
	end_point = L.end_point;
	color = L.color;
}

Line& Line::operator=(const Line& L){
	start_point = L.start_point;
	end_point = L.end_point;
	color = L.color;
	return *this;
}


void Line::draw(){

	int x0 = CENTERX;
	int y0 = CENTERY;
	
	//Algoritma line bresenham
	// deklarasi variabel
	double temp; // variabel sementara untuk penyimpanan saat swaping
	double dx, dy; // selisih nilai start_point.x dg end_point.x dan start_point.y dg end_point.y
	int p; // parameter function
	int c0, c1; // konstanta parameter function
	int x, y; // untuk iterasi pixel
	int state; // 0:menyatakan iterasi pada x (normal), 1:menyatakan iterasi pada y

	// preinisiasi
	dx = end_point.x-start_point.x;
	dy = end_point.y-start_point.y;

	// algoritma
	if (abs(dx) < abs(dy)) { // garis menanjak (abs(m) > 1), iterasi pada y
		state = 1;
		
		// pertukarkan nilai x dengan y
		temp = start_point.x;
		start_point.x = start_point.y;
		start_point.y = temp;
		
		temp = end_point.x;
		end_point.x = end_point.y;
		end_point.y = temp;
	} else { // garis melandai (0 < abs(m) <= 1), iterasi pada x
		state = 0;
	}

	// memastikan start_point.x < end_point.x
	if (start_point.x > end_point.x) {
		temp = start_point.x;
		start_point.x = end_point.x;
		end_point.x = temp;

		temp = start_point.y;
		start_point.y = end_point.y;
		end_point.y = temp;
	}
	
	// inisiasi
	dx = end_point.x-start_point.x;
	dy = end_point.y-start_point.y;
	
	p = 2*dy-dx;
	c0 = 2*dy;
	c1 = 2*(dy-dx);
	if (dy < 0) {
		p *= -1;
		c0 *= -1;
		c1 = -2*(dy+dx);
	}
	
	// inisiasi pixel
	x = start_point.x;
	y = start_point.y;
	
	if (state) {
		//putpixel(y+x0, -x+y0, color);
		canvas_putpixel(y+x0, -x+y0, color);
	} else {
		//putpixel(x+x0, -y+y0, color);
		canvas_putpixel(x+x0, -y+y0, color);
	}
	
	// iterasi pixel
	for (x = start_point.x+1; x < end_point.x; x++) {
		// menentukan nilai p selanjutnya
		if (p < 0) { // nilai y selanjutnya sama dengan y sekarang
			p += c0;
		} else { // nilai y selanjutnya lebih/kurang 1 dari y sekarang
			p += c1;
			if (dy < 0) {
				y--;
			} else {
				y++;
			}
		}
		
		if (state) {
			//putpixel(y+x0, -x+y0, color);
		} else {
			//putpixel(x+x0, -y+y0, color);
			canvas_putpixel(x+x0, -y+y0, color);
		}
	}
}

}

void Line::translate(double dx, double dy){
	int points[4];
	points[0] = start_point.x;
	points[1] = start_point.y;
	points[2] = end_point.x;
	points[3] = end_point.y;
	translation(points, 2, dx, dy);
	start_point.x = points[0];
	start_point.y = points[1];
	end_point.x   = points[2];
	end_point.y   = points[3];
}

void Line::scale(double, Point){
}

void Line::rotate(double,Point){
}

void Line::reflect(double, Point){
}

void Line::shear(double, double, Point){
}
