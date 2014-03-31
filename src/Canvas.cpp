#include "Canvas.hpp"
#include <cstdlib>
#include <iostream>
#include <deque>

Canvas::Canvas() {
	page = 0;
	drawing = false;
	
	int gd = DETECT, gm = VGAHI;
	initgraph( &gd, &gm, "" );
}

Canvas::~Canvas() {
	closegraph();
}

void Canvas::BeginDraw() {
	drawing = true;
	setactivepage( InactivePage() );
	cleardevice();
}

void Canvas::EndDraw() {
	drawing = false;
	setvisualpage( InactivePage() );
	
	page = InactivePage();
}

void Canvas::DrawLine(Line line, int color) { // Algoritma line bresenham
	// KASUS I: Kalo garis hor/ver langsung ajah, ngapain ribet2
	if (line.P0.x == line.P1.x) { // hor
		int start = (line.P0.y < line.P1.y) ? line.P0.y : line.P1.y;
		int end = (line.P0.y > line.P1.y) ? line.P0.y : line.P1.y;
		for (int i = start; i <= end; i++) {
			putpixel(line.P0.x, i, color);
		}
		return;
	}
	
	if (line.P0.y == line.P1.y) { //  ver
		int start = (line.P0.x < line.P1.x) ? line.P0.x : line.P1.x;
		int end = (line.P0.x > line.P1.x) ? line.P0.x : line.P1.x;
		for (int i = start; i <= end; i++) {
			putpixel(i, line.P0.y, color);
		}
		return;
	}
	
	// KASUS II: Miring garisnya, mau ga mau ya mau
	int m; // mode iterasi: 0-iterasi pada x (normal); 1-iterasi pada y

	// algoritma preinisiasi
	int dx = line.P1.x - line.P0.x;
	int dy = line.P1.y - line.P0.y;

	if (ABS(dx) < ABS(dy)) { // garis menanjak (abs(m) > 1), iterasi pada y
		m = 1;
		
		// pertukarkan nilai x dengan y untuk kedua titik
		line.P0.Swap();
		line.P1.Swap();
	} else { // garis melandai (0 < abs(m) <= 1), iterasi pada x
		m = 0;
	}

	// memastikan P0.x <= P1.x
	if (line.P0.x > line.P1.x) {
		int temp;
		
		temp = line.P0.x;
		line.P0.x = line.P1.x;
		line.P1.x = temp;

		temp = line.P0.y;
		line.P0.y = line.P1.y;
		line.P1.y = temp;
	}
	
	// algoritma
	// inisiasi
	dx = line.P1.x - line.P0.x;
	dy = line.P1.y - line.P0.y;
	
	// inisiasi fungsi parameter
	int p = 2*dy-dx;
	int c0 = 2*dy; // konstanta 1
	int c1 = 2*(dy-dx); // konstanta 2
	
	if (dy < 0) {
		p *= -1;
		c0 *= -1;
		c1 = -2*(dy+dx);
	}
	
	// inisiasi pixel
	int x = line.P0.x;
	int y = line.P0.y;
	
	if (m) {
		putpixel(y, x, color);
	} else {
		putpixel(x, y, color);
	}
	
	// iterasi pixel
	for (x = line.P0.x + 1; x <= line.P1.x; x++) {
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
		
		if (m) {
			putpixel(y, x, color);
		} else {
			putpixel(x, y, color);
		}
	}
}

void Canvas::DrawDash(Line line, int on_length, int off_length, int color) { // pake algoritma bresenham
	// KASUS I: Kalo garis hor/ver langsung ajah, ngapain ribet2
	if (line.P0.x == line.P1.x) { // hor
		int start = (line.P0.y < line.P1.y) ? line.P0.y : line.P1.y;
		int end = (line.P0.y > line.P1.y) ? line.P0.y : line.P1.y;
		int counter = 0;
		for (int i = start; i <= end; i++) {
			if (counter < on_length)
				putpixel(line.P0.x, i, color);
			
			counter++;
			
			if (counter == on_length + off_length)
				counter = 0;
		}
		return;
	}
	
	if (line.P0.y == line.P1.y) { //  ver
		int start = (line.P0.x < line.P1.x) ? line.P0.x : line.P1.x;
		int end = (line.P0.x > line.P1.x) ? line.P0.x : line.P1.x;
		int counter = 0;
		for (int i = start; i <= end; i++) {
			if (counter < on_length)
				putpixel(i, line.P0.y, color);
			
			counter++;
			
			if (counter == on_length + off_length)
				counter = 0;
		}
		return;
	}
	
	// KASUS II: Miring garisnya, mau ga mau ya mau
	int m; // mode iterasi: 0-iterasi pada x (normal); 1-iterasi pada y

	// algoritma preinisiasi
	int dx = line.P1.x - line.P0.x;
	int dy = line.P1.y - line.P0.y;

	if (ABS(dx) < ABS(dy)) { // garis menanjak (abs(m) > 1), iterasi pada y
		m = 1;
		
		// pertukarkan nilai x dengan y untuk kedua titik
		line.P0.Swap();
		line.P1.Swap();
	} else { // garis melandai (0 < abs(m) <= 1), iterasi pada x
		m = 0;
	}

	// memastikan P0.x <= P1.x
	if (line.P0.x > line.P1.x) {
		int temp;
		
		temp = line.P0.x;
		line.P0.x = line.P1.x;
		line.P1.x = temp;

		temp = line.P0.y;
		line.P0.y = line.P1.y;
		line.P1.y = temp;
	}
	
	// algoritma
	// inisiasi
	dx = line.P1.x - line.P0.x;
	dy = line.P1.y - line.P0.y;
	
	// inisiasi fungsi parameter
	int p = 2*dy-dx;
	int c0 = 2*dy; // konstanta 1
	int c1 = 2*(dy-dx); // konstanta 2
	
	if (dy < 0) {
		p *= -1;
		c0 *= -1;
		c1 = -2*(dy+dx);
	}
	
	// inisiasi pixel
	int x = line.P0.x;
	int y = line.P0.y;
	
	if (m) {
		putpixel(y, x, color);
	} else {
		putpixel(x, y, color);
	}
	
	int counter = 0;
	
	// iterasi pixel
	for (x = line.P0.x + 1; x <= line.P1.x; x++) {
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
		
		if (m) {
			if (counter < on_length)
				putpixel(y, x, color);
			
			counter++;
			
			if (counter == on_length + off_length)
				counter = 0;
		} else {
			if (counter < on_length)
				putpixel(x, y, color);
			
			counter++;
			
			if (counter == on_length + off_length)
				counter = 0;
		}
	}
}

void Canvas::DrawCircle(Circle circle) {
	double xCenter = circle.C.x;
	double yCenter = circle.C.y;
    
    int x = 0;
	int y = (int) circle.R;
    int p = 1 - (int) circle.R;
	
	int color = circle.color;

	putpixel(xCenter + x, yCenter + y, color);
    putpixel(xCenter - x, yCenter + y, color);
    putpixel(xCenter + x, yCenter - y, color);
    putpixel(xCenter - x, yCenter - y, color);
    putpixel(xCenter + y, yCenter + x, color);
    putpixel(xCenter - y, yCenter + x, color);
    putpixel(xCenter + y, yCenter - x, color);
    putpixel(xCenter - y, yCenter - x, color);

    while (x < y) {
	x++;
	if (p < 0)
	    p += (x << 1) + 1;
	else {
	    y--;
	    p += ((x - y) << 1) + 1;
	}
	
	putpixel(xCenter + x, yCenter + y, color);
    putpixel(xCenter - x, yCenter + y, color);
    putpixel(xCenter + x, yCenter - y, color);
    putpixel(xCenter - x, yCenter - y, color);
    putpixel(xCenter + y, yCenter + x, color);
    putpixel(xCenter - y, yCenter + x, color);
    putpixel(xCenter + y, yCenter - x, color);
    putpixel(xCenter - y, yCenter - x, color);
    }
}

void Canvas::Fill(Point P, int oldColor, int newColor) {
	if (newColor == oldColor)
		return;
	
	std::deque<Point> Q;
	Q.push_back(P);
	while (!Q.empty()) {
		Point currP = Q.front();
		Q.pop_front();
		if ((int) getpixel(currP.x, currP.y) == oldColor) {
			putpixel(currP.x, currP.y, newColor);
			Q.push_back(Point(currP.x + 1, currP.y    ));
			Q.push_back(Point(currP.x - 1, currP.y    ));
			Q.push_back(Point(currP.x    , currP.y + 1));
			Q.push_back(Point(currP.x    , currP.y - 1));
		}
	}
}

void Canvas::FillRect(int left, int bottom, int right, int up, int color) {
	for (int i = up + 1; i < bottom; i++) {
		for (int j = left + 1; j < right; j++) {
			putpixel(j, i, color);
		}
	}
}

const int Canvas::InactivePage() const {
	return ( page == 1 ) ? 0 : 1;
}
