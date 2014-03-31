/*
 * The region bit convention
 *  _      _      _     _
 * |_|    |_|    |_|   |_|
 *  
 * Left  Right  Bottom Top
 */
 
#define hTop 160
#define hBottom 480
#define wLeft 120
#define wRight 360

typedef struct{
	int offsetX;
	int offsetY;
	int width;
	int height;
	Point origin;
} GWindow;
 
// Returns the region code of a point
int findRegion(int x, int y) {
	int code = 0;
	if(y <= hTop)
	code |= 1; //top
	else if(y >= hBottom)
	code |= 2; //bottom
	if(x >= wRight)
	code |= 4; //right
	else if(x <= wLeft)
	code |= 8; //left
	return(code);
}

// Clip a line with two points.
// x3, y3, x4, and y4 will become the new point
bool clipLine(int x1, int y1, int x2, int y2, int & x3, int & y3, int & x4, int & y4) {
	int code1, code2, codeout;
	bool accept = false, done = false;
	code1 = findRegion(x1, y1); //the region outcodes for the endpoints
	code2 = findRegion(x2, y2);
	do  //In theory, this can never end up in an infinite loop, it'll always come in one of the trivial cases eventually
	{
		if(!(code1 | code2)) accept = done = true;  //accept because both endpoints are in screen or on the border, trivial accept
		else if(code1 & code2) done = true; //the line isn't visible on screen, trivial reject
		else  //if no trivial reject or accept, continue the loop 
		{
			int x, y;
			codeout = code1 ? code1 : code2;
			if(codeout & 1) //top 
			{
				x = x1 + (x2 - x1) * (hTop - y1) / (y2 - y1);
				y = h - 1;
			}
			else if(codeout & 2) //bottom 
			{
				x = x1 + (x2 - x1) * (hBottom - y1) / (y2 - y1);
				y = 0;
			}
			else if(codeout & 4) //right 
			{
				y = y1 + (y2 - y1) * (wRight - x1) / (x2 - x1);
				x = w - 1;
			}
			else //left 
			{
				y = y1 + (y2 - y1) * (wLeft - x1) / (x2 - x1);
				x = 0;
			}
			
			if(codeout == code1) //first endpoint was clipped 
			{
				x1 = x; y1 = y;
				code1 = findRegion(x1, y1);
			}
			else //second endpoint was clipped 
			{
				x2 = x; y2 = y;
				code2 = findRegion(x2, y2);
			}
		}
	} while(!done);
	
	if(accept) {
		x3 = x1;
		x4 = x2;
		y3 = y1;
		y4 = y2;
		return 1;
	}
	else {
		x3 = x4 = y3 = y4 = 0;
		return 0;
	}
}

void drawWindow(GWindow w){
	int i;
	for (i=0; i<w.width; i++){
		putpixel(w.offsetX+i, w.offsetY, GREEN);
		putpixel(w.offsetX+i, w.offsetY+w.height, GREEN);
	}
	for (i=0; i<w.height; i++){
		putpixel(w.offsetX, w.offsetY+i, GREEN);
		putpixel(w.offsetX+w.width, w.offsetY+i, GREEN);
	}
}

void drawWindowOnWindow(GWindow w, GWindow g){
	int i;
	for (i=0; i<w.width; i++){
		putpixel(g.origin.x+w.offsetX+i, g.origin.y-w.offsetY, GREEN);
		putpixel(g.origin.x+w.offsetX+i, g.origin.y-w.offsetY+w.height, GREEN);
	}
	for (i=0; i<w.height; i++){
		putpixel(g.origin.x+w.offsetX, g.origin.y-w.offsetY+i, GREEN);
		putpixel(g.origin.x+w.offsetX+w.width, g.origin.y-w.offsetY+i, GREEN);
	}
}

int main() {
	int gd = DETECT, gm;
    int i;
    double t;
    initgraph (&gd, &gm, "");
	GWindow window = makeWindow(0,0,320,480);
	GWindow viewport = makeWindow(320,0,320,480);
	GWindow clipWindow = makeWindow(-40,60,80,120);
	Point p1 = makePoint(-70,-70);
	Point p2 = makePoint(0,70);
	Line l = makeLine(p1, p2);
	char command;
	do{
		system("cls");
		cleardevice();
		drawWindow(viewport);
		drawWindow(window);
		drawWindowOnWindow(clipWindow, window);
		drawLineOnWindow(l, RED, window);
		clipLine(l,clipWindow,viewport,window);
		command = getch();
		if(command == 'w'){
			if (clipWindow.offsetY < (window.height/2))
				clipWindow.offsetY += 5;
		}
		else if(command == 's'){
			if (clipWindow.offsetY > clipWindow.height-(window.height/2))
				clipWindow.offsetY -= 5;
		}
		else if(command == 'a'){
			if (clipWindow.offsetX > -(window.width/2))
				clipWindow.offsetX -= 5;
		}
		else if(command == 'd'){
			if (clipWindow.offsetX < (window.width/2)-clipWindow.width)
				clipWindow.offsetX += 5;
		}
		else if(command == '='){
			if (clipWindow.width<=320){
				clipWindow.width *= 2;
				clipWindow.height *= 2;
			}
		}
		else if(command == '-'){
			if (clipWindow.width>=20){
				clipWindow.width = clipWindow.width/2;
				clipWindow.height = clipWindow.height/2;
			}
			if (clipWindow.offsetX <= -(window.height/2))
				clipWindow.offsetX = -(window.height/2);
		}
		if (clipWindow.offsetY >= window.height/2)
				clipWindow.offsetY = window.height/2;
		if (clipWindow.offsetY <= clipWindow.height-(window.height/2))
				clipWindow.offsetY = clipWindow.height-(window.height/2);
		if (clipWindow.offsetX <= -(window.height/2))
				clipWindow.offsetX = -(window.height/2);
		if (clipWindow.offsetX >= (window.width/2)-clipWindow.width)
				clipWindow.offsetX = (window.width/2)-clipWindow.width;
	} while (command != 'x');
	return 0;
}