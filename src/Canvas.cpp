#include "Canvas.hpp"

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
}

void Canvas::EndDraw() {
	drawing = false;
	setvisualpage( InactivePage() );
	page = InactivePage();
}

void Canvas::DrawLine(Line line, int color) { // Algoritma line bresenham
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
	for (x = line.P0.x + 1; x < line.P1.x; x++) {
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

//void Canvas::DrawCircle(Circle circle, int color) {}

void Canvas::Fill(Point P, int color) {
	
}

void Canvas::FillFlood(Point P, int newColor, int oldColor) {
	if (P.x >= 0 && P.x < getmaxx() && P.y >= 0 && P.y < getmaxy() && getpixel(P.x, P.y) == oldColor) {
		int x = P.x;
		int y = P.y;
		putpixel(x, y, newColor);
		FillFlood(Point(x+1, y  ), newColor, oldColor);
		FillFlood(Point(x-1, y  ), newColor, oldColor);
		FillFlood(Point(x  , y+1), newColor, oldColor);
		FillFlood(Point(x  , y-1), newColor, oldColor);
	}
}

const int Canvas::InactivePage() const {
	return ( page == 1 ) ? 0 : 1;
}