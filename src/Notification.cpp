#include "Notification.hpp"

Notification::Notification() {
	lines.push_back(Line(Point(100,100), Point(100, 400), BLACK));
	lines.push_back(Line(Point(100,400), Point(600, 400), BLACK));
	lines.push_back(Line(Point(600,400), Point(600, 100), BLACK));
	lines.push_back(Line(Point(600,100), Point(100, 100), BLACK));
	
	isLarger = false;
	counter = 29;
}

Notification::~Notification() {}

void Notification::Update() {
	if (counter % 2 == 0) {
		for (int i = 0; i < lines.size(); i++) {
			if (isLarger) {
				lines[i].Scale(2, Point(320,220));
				if (lines[0].P0.x < 200) {
					isLarger = false;
				}
			} else {
				lines[i].Scale(0.5, Point(320,220));
				if (lines[0].P0.x > 300) {
					isLarger = true;
				}
			}
		}
	}
	
	if (counter == 0) {
		counter = 2;
	}
	
	counter--;
}

void Notification::Draw(Canvas& canvas) {
	for (int i = 0; i < lines.size(); i++) {
		canvas.DrawLine(lines[i], BLACK);
	}
	
	canvas.FillRect(lines[0].P0.x, lines[1].P0.y, lines[2].P0.x, lines[3].P0.y, BLACK);
}