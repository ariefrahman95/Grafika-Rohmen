#include <iostream>
#include "Line.hpp"
#include "TimeBar.hpp"
using namespace std;

TimeBar::TimeBar() {
	position = Point(10,10);
	
	color_fill = LIGHTCYAN;
	color_border = WHITE;
	
	isTimeUp = false;
	
	// membuat time bar untuk lifetime 30 detik
	lines.push_back(Line(Point(10,15) , Point(10,465), color_border));
	lines.push_back(Line(Point(10,465), Point(40,465), color_border));
	lines.push_back(Line(Point(40,465), Point(40,15) , color_border));
	lines.push_back(Line(Point(40,15) , Point(10,15) , color_border));
	
	counter = 29;
}

TimeBar::~TimeBar() {}

void TimeBar::Update() {
	// kurangin tinggi time bar sebanyak 1 pixel setiap 1/15 detik
	if (counter % 2 == 0) {
		lines[0].P0.y += 1;
		lines[2].P1.y += 1;
		lines[3].P0.y += 1;
		lines[3].P1.y += 1;
	}

	if (counter == 0) {
		counter = 2;
	}
	
	counter--;
	
	// kalo udah tinggal 5 detik, ubah warna time bar jadi merah
	if (lines[0].P0.y == 390) {
		//color_border = 5;
		color_fill = LIGHTRED;
		//for (int i = 0; i < lines.size(); i++) {
		//	lines[i].color = color_border;
		//}
	}
	
	// waktunya udah abis
	if (lines[0].P0.y == 465) {
		isTimeUp = true;
	}
}

void TimeBar::Draw(Canvas& canvas) {
	for (int i = 0; i < lines.size(); i++) {
		canvas.DrawLine(lines[i], color_border);
	}
	
	//canvas.Fill(Point(25, 464), getpixel(25, 464), 8);
	canvas.FillRectangle(lines[1].P0.x, lines[0].P1.y, lines[1].P1.x, lines[0].P0.y, color_fill);
}

bool TimeBar::IsTimeUp() {
	return isTimeUp;
}