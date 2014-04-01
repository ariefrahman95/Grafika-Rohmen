#include "Barrier.hpp"
#include <cstdlib>
#include <time.h>

Barrier::Barrier() {}

Barrier::Barrier(int type) {
	srand(time(NULL));
	lane = rand() % 3;
	if (type == WHEEL) {
		Point p(320, 220);
		wheel.C = p;
		wheel.R = 1;
		wheel.color = 255;
	} else if (type == WOOD) {
		// Kayu bentuknya kotak ajah
		wood.push_back(Line(Point(318, 218), Point(318, 220), BROWN));
		wood.push_back(Line(Point(318, 220), Point(322, 220), BROWN));
		wood.push_back(Line(Point(322, 220), Point(322, 218), BROWN));
		wood.push_back(Line(Point(322, 218), Point(318, 218), BROWN));
		
		if (lane == 0) {
			for (int i = 0; i < wood.size(); i++) {
				wood[i].Translate(-5, 0);
			}
		} else if (lane == 2) {
			for (int i = 0; i < wood.size(); i++) {
				wood[i].Translate(5, 0);
			}
		}
	} else if(type == STONE) {
		Point p(320, 220);
		wheel.C = p;
		wheel.R = 1;
		wheel.color = 64;
	}
	this->type = type;
	
	counter = 29;
}

void Barrier::Draw(Canvas& canvas) {
	if (type == WHEEL) {
		canvas.DrawCircle(wheel);
	} else if (type == WOOD) {
		// gambar bordernya
		for (int i = 0; i < wood.size(); i++) {
			canvas.DrawLine(wood[i], BROWN);
		}
		
		// terus diisi warna
		canvas.FillRect(wood[0].P0.x, wood[1].P0.y, wood[2].P0.x, wood[3].P0.y, BROWN);
	}
	else if(type == STONE);
}

void Barrier::Update() {
	if (counter % 2 == 0) {
		if (type == WHEEL) {
			if (wheel.R < 40) wheel.R++;
			if (lane == 0) {
				wheel.C.x--;
			}
			else if (lane == 2) {
				wheel.C.x++;
			}
			wheel.C.y++;
		} else if (type == WOOD) {
			// gedein ampe mentok bawah
			if (wood[1].P0.y < 480 && wood[1].P1.y < 480 && wood[3].P0.y < 480 && wood[3].P1.y < 480) {
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Scale(1.1, Point(320, 210));
				}
			} else { // kalo udah di bawah, kita lempar ke kanan
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Translate(5, 0);
					wood[i].Rotate(5, Point((wood[0].P0.x + wood[2].P0.x)/2, (wood[1].P0.y + wood[3].P0.y)/2));
				}
			}
			
			// kalo udah keluar layar, kita ke atasin lagi
			if ((wood[0].P0.x > 640 || wood[0].P0.y > 480) && (wood[1].P0.x > 640 || wood[1].P0.y > 480) && (wood[2].P0.x > 640 || wood[2].P0.y > 480) && (wood[3].P0.x > 640 || wood[3].P0.y > 480)) {
				wood.clear();
				wood.push_back(Line(Point(318, 218), Point(318, 220), BROWN));
				wood.push_back(Line(Point(318, 220), Point(322, 220), BROWN));
				wood.push_back(Line(Point(322, 220), Point(322, 218), BROWN));
				wood.push_back(Line(Point(322, 218), Point(318, 218), BROWN));
			}
			
			// gerakin kayunya tergantung ada di Lane berapa
			/*if (lane == 0) { // ke kiri bawah
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Translate(-1, -1);
				}
			} else if (lane == 1) { // ke bawah aja
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Translate(0, -1);
				}
			} else if (lane == 2) { // ke kanan bawah
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Translate(1, -1);
				}
			}*/
		} else if (type == STONE) {
			Point p(320, 0);
			if(wheel.R <= 75) wheel.R++;
			wheel.C.x--;
			wheel.C.y++;
		}
	}
	
	if (counter == 0) {
		counter = 2;
	}
	
	counter--;
}
