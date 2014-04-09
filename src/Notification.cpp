#include "Notification.hpp"

Notification::Notification() {
	lines.push_back(Line(Point(315,218), Point(315,222), BLACK));
	lines.push_back(Line(Point(315,222), Point(325,222), BLACK));
	lines.push_back(Line(Point(325,222), Point(325,218), BLACK));
	lines.push_back(Line(Point(325,218), Point(315,218), BLACK));
	
	max = 512;
	//counter = 2;
}

Notification::~Notification() {}

void Notification::Update() {
	//if (counter == 0) {
		if (lines[3].P0.x - lines[3].P1.x < max) {
			for (int i = 0; i < lines.size(); i++) {
				lines[i].Scale(2, Point(320,220));
			}
		}
	//}
	
	//if (counter == 0) {
	//	counter = 2;
	//}
	
	//counter--;
}

void Notification::Draw(Canvas& canvas) {
	for (int i = 0; i < lines.size(); i++) {
		canvas.DrawLine(lines[i], BLACK);
	}
	
	canvas.FillRect(lines[0].P0.x, lines[1].P0.y, lines[2].P0.x, lines[3].P0.y, BLACK);
}