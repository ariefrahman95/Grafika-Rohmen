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

const int Canvas::InactivePage() const {
	return ( page == 1 ) ? 0 : 1;
}