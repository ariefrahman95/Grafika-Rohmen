#include <graphics.h>
#include <iostream>
using namespace std;

// Still doing hello world; let's change it, guys.
int main()
{
	int gd = DETECT, gm = 0;
	initgraph( &gd, &gm, "" );
	
	cout << "Hello World!" << endl;
	while ( !anykeypressed() ) { }
	
	closegraph();
}
