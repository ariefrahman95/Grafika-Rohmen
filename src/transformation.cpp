#include <math.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void translation(int points[], int edges, int dx, int dy) {
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

int main() {
	int points[20];		// List of edges that make the points
	int numEdges;		// Number of edges
	
	// Initiate graphics function
	int gd = DETECT, gm;
	initgraph( &gd, &gm, "" );
	
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
		edges += 1;
	}
	
	int choice = 0;
	while(choice != 1 && choice != 2 && choice != 3) {
		printf("Choose transformation (1 : Translation, 2: Rotation, 3: Scaling) :");
		scanf("%d", &choice);
	}
	
	switch(choice) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
	}
}