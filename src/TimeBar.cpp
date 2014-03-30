#include <iostream>
#include "Line.hpp"
#include "TimeBar.hpp"
using namespace std;

TimeBar::TimeBar() {
	position = Point(10,10);
	
	color_fill = 5;
	color_border = 10;
	
	strokes.push_back(Line(Point(10,10) , Point(10,470), color_border));
	strokes.push_back(Line(Point(10,470), Point(40,470), color_border));
	strokes.push_back(Line(Point(40,470), Point(40,10) , color_border));
	strokes.push_back(Line(Point(40,10) , Point(10,10) , color_border));
	
	counter = 0;
}

TimeBar::~TimeBar() {}

void TimeBar::Update() {
	if (counter % 30 == 0) {
		strokes[0].P0.y += 10;
		strokes[2].P1.y += 10;
		strokes[3].P0.y += 10;
		strokes[3].P1.y += 10;
	}
	counter++;
	if (counter == 30) {
		counter = 0;
	}
}

void TimeBar::Draw(Canvas& canvas) {
	for (int i = 0; i < strokes.size(); i++) {
		canvas.DrawLine(strokes[i], color_border);
	}
	//canvas.FillFlood(Point(25,240), color_fill, 0);
}
