#include <iostream>
#include "Line.hpp"
#include "TimeBar.hpp"
using namespace std;

TimeBar::TimeBar() {
	position = Point(10,10);
	
	color_fill = 5;
	color_border = 10;
	
	lines.push_back(Line(Point(10,10) , Point(10,470), color_border));
	lines.push_back(Line(Point(10,470), Point(40,470), color_border));
	lines.push_back(Line(Point(40,470), Point(40,10) , color_border));
	lines.push_back(Line(Point(40,10) , Point(10,10) , color_border));
	
	counter = 29;
}

TimeBar::~TimeBar() {}

void TimeBar::Update() {
	if (counter % 30 == 0) {
		lines[0].P0.y += 10;
		lines[2].P1.y += 10;
		lines[3].P0.y += 10;
		lines[3].P1.y += 10;
	}

	if (counter == 0) {
		counter = 29;
	}
	
	counter--;
}

void TimeBar::Draw(Canvas& canvas) {
	for (int i = 0; i < lines.size(); i++) {
		canvas.DrawLine(lines[i], color_border);
	}
	//canvas.FillFlood(Point(25,240), color_fill, 0);
}
