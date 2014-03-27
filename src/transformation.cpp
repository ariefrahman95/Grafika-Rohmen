#include<math.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void translation(double points[], int edges, double dx, double dy) {
	int i; // Iterator
	for(i = 0; i < edges; i++) {
		points[2*i] += dx;
		points[2*i+1] += dy;
	}
}

void scale(int points[], int edges, int dx, int dy, int cx, int cy){
	for(int i=0; i < edges; i++) {
		points[2*i] = (points[2*i] - cx) * dx + cx;
		points[2*i+1] = (points[2*i+1] - cy) * dy + cy;
	}
}

void rotate(int points[], int edges, double angle, int cx, int cy) {
	double x, y;
	angle = -1 * (angle*3.14/180);
	double cos_a = cos(angle);
	double sin_a = sin(angle);
 
	for(int i=0; i < edges; i++) {
		x = points[2*i] - cx;
		y = points[2*i+1] - cy;
		points[2*i] = floor((x * cos_a) - (y * sin_a) + cx + 0.5);
		points[2*i+1] = floor((x * sin_a)+(y * cos_a) + cy + 0.5);
	}
}

void reflect(int points[], int edges, int option) {
	switch(option) {
		case 1:
			// Reflect by x-axis
			for(int i=0; i < edges; i++) {
				points[2*i] = -points[2*i];
			}
			break;
		case 2:
			// Reflect by y-axis
			for(int i=0; i < edges; i++) {
				points[2*i+1] = -points[2*i+1];
			}
			break;
		case 3:
			// Reflect by y = x line
			for(int i=0; i < edges; i++) {
				int temp = points[2*i];
				points[2*i] = points[2*i+1];
				points[2*i+1] = temp;
			}
			break;
	}
}

void shear(int points[], int edges, double shx, double shy, int cx, int cy) {
	for(int i=0; i < edges; i++) {
		int temp = points[2*i];
		points[2*i] += (int) points[2*i+1] * shx - cx;
		points[2*i+1] += (int)  * shy - cy;
	}
}

int main() {
	int points[20];		// List of edges that make the points
	int numEdges;		// Number of edges
	
	// Initiate graphics function
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	clrscr();
	cleardevice();
	
	int maxX = getmaxx();
	int maxY = getmaxy();
	
	printf("Enter number of edges(maximum 9): ");
	scanf("%d", &edges);
	
	if(edges > 9) {
		printf("Maximum number of edges exceeded.\n");
		exit(0);
	} else {
		for(int i=0; i < edges; i++)
		{
			printf("Enter coordinate (x%d,y%d) : ", i , i);
			scanf("%d %d", &points[2*i], &points[2*i+1]);
		}
		points[2*i] = points[0];
		points[2*i+1] = points[1];
		edges++;
	}
	
	setbkcolor(WHITE);
	setcolor(GREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	drawpoly(edges, figure);
	
	int choice = 0;
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
		printf("Choose transformation (1 : Translation, 2: Rotate, 3: Scale, 4:Reflect, 5: Shear) :");
		scanf("%d", &choice);
	}
	
	switch(choice) {
		case 1:
			int dx, dy;
			printf("Enter dx: ");
			scanf("%d", &dx);
			printf("Enter dy: ");
			scanf("%d", &dy);
			
			translation(figure,edges,dx,dy);
			
			setcolor(RED);
			drawpoly(edges, figure);
			break;
		case 2:
			int cx, cy;
			double angle;
			
			printf( "Enter angle of rotation in degrees: ");
			scanf("%lf", &angle);
		 
			printf("Enter the center of rotation: \n");
			printf("cx: ");
			scanf("%d", &cx);
			printf("cy: ");
			scanf("%d", &cy);
			
			for(int i=0; i < edges; i++)
				figure[2*i+1] = maxY - figure[2*i+1];
			rotate(figure,edges,angle,cx,cy);
			for(int i=0; i < edges; i++)
				figure[2*i+1] = maxY - figure[2*i+1];
				
			cy = maxY - cy;
			
			setcolor(RED);
			drawpoly(edges, figure);
			break;
		case 3:
			int dx, dy, cx, cy;
			printf("Enter dx: ");
			scanf("%d", &dx);
			printf("Enter dy: ");
			scanf("%d", &dy);
	 
			printf("Enter the center of scaling: \n");
			printf("cx: ");
			scanf("%d", &cx);
			printf("cy: ");
			scanf("%d", &cy);
			
			scale(figure,edges,dx,dy,cx,cy);
			
			setcolor(RED);
			drawpoly(edges, figure);
			break;
	}
	getch();
}