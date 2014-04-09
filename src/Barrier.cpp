#include "Barrier.hpp"
#include <cstdlib>
#include <time.h>

Barrier::Barrier() {}

Barrier::Barrier(int type) {
	srand(time(NULL));
	lane = rand() % 3;
	if (type == WHEEL) {
		wheel.push_back(Circle(Point(320, 220), 1, RED));
		wheel.push_back(Circle(Point(320, 220.5), 0.25, MAGENTA));
		
		lane--;
		
		if (lane == 0) {
			for (int i = 0; i < wheel.size(); i++) {
				wheel[i].Translate(-5, 0);
			}
		} else if (lane == 2) {
			for (int i = 0; i < wheel.size(); i++) {
				wheel[i].Translate(5, 0);
			}
		}
	} else if (type == WOOD) {
		// Kayu bentuknya kotak ajah
		wood.push_back(Line(Point(319, 219), Point(319, 220), BROWN));
		wood.push_back(Line(Point(319, 220), Point(321, 220), BROWN));
		wood.push_back(Line(Point(321, 220), Point(321, 219), BROWN));
		wood.push_back(Line(Point(321, 219), Point(319, 219), BROWN));
		
		if (lane == 0) {
			for (int i = 0; i < wood.size(); i++) {
				wood[i].Translate(-5, 0);
			}
		} else if (lane == 2) {
			for (int i = 0; i < wood.size(); i++) {
				wood[i].Translate(5, 0);
			}
		}
	} else if (type == STONE) {
		stone.push_back(Line(Point(320, 219), Point(319, 220), BROWN));
		stone.push_back(Line(Point(319, 220), Point(321, 220), BROWN));
		stone.push_back(Line(Point(321, 220), Point(320, 219), BROWN));
		
		lane++;
		
		if (lane == 0) {
			for (int i = 0; i < stone.size(); i++) {
				stone[i].Translate(-5, 0);
			}
		} else if (lane == 2) {
			for (int i = 0; i < stone.size(); i++) {
				stone[i].Translate(5, 0);
			}
		}
	}
	
	this->type = type;
	
	counter = 29;
}

void Barrier::Draw(Canvas& canvas) {
	if (type == WHEEL) {
		for (int i = 0; i < wheel.size(); i++) {
			canvas.DrawCircle(wheel[i]);
		}
		
		for (int i = 0; i < wheel.size(); i++) {
			canvas.FillFlood(wheel[i].C, getpixel(wheel[i].C.x, wheel[i].C.y), wheel[i].color);
		}
	} else if (type == WOOD) {
		// gambar bordernya
		for (int i = 0; i < wood.size(); i++) {
			canvas.DrawLine(wood[i], BROWN);
		}
		
		// terus diisi warna
		double X = (wood[0].P0.x + wood[2].P0.x)/2;
		double Y = (wood[0].P0.y + wood[2].P0.y)/2;
		canvas.FillFlood(Point(X,Y), getpixel(X,Y), BROWN);
		//canvas.FillRect(wood[0].P0.x, wood[1].P0.y, wood[2].P0.x, wood[3].P0.y, BROWN);
	} else if (type == STONE) {
		for (int i = 0; i < stone.size(); i++) {
			canvas.DrawLine(stone[i], YELLOW);
		}
		
		double X = (stone[0].P0.x + stone[1].P0.x + stone[2].P0.x)/3;
		double Y = (stone[0].P0.y + stone[1].P0.y + stone[2].P0.y)/3;
		canvas.FillFlood(Point(X,Y), getpixel(X,Y), YELLOW);
	}
}

void Barrier::Update() {
	if (counter % 2 == 0) {
		if (type == WHEEL) {
			if (IsWheelFront()) {
				for (int i = 0; i < wheel.size(); i++) {
					wheel[i].Scale(1.1, Point(320, 210));
				}
			} else {
				double x = wheel[0].C.x;
				double y = wheel[0].C.y;
				for (int i = 0; i < wheel.size(); i++) {
					wheel[i].Rotate(30, Point(x,y));
					wheel[i].Translate(10, 0);
				}
			}
			
			if (wheel[0].C.x + wheel[0].R > 640) {
				wheel.clear();
				
				wheel.push_back(Circle(Point(320, 220), 1, RED));
				wheel.push_back(Circle(Point(320, 220.5), 0.25, MAGENTA));
				
				lane = rand() % 3;
				
				if (lane == 0) {
					for (int i = 0; i < wheel.size(); i++) {
						wheel[i].Translate(-5, 0);
					}
				} else if (lane == 2) {
					for (int i = 0; i < wheel.size(); i++) {
						wheel[i].Translate(5, 0);
					}
				}
			}
		} else if (type == WOOD) {
			// gedein ampe mentok bawah
			if (IsWoodFront()) {
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Scale(1.05, Point(320, 210));
				}
			} else { // kalo udah di bawah, kita lempar ke kanan
				double x = (wood[0].P0.x + wood[2].P0.x)/2;
				double y = (wood[1].P0.y + wood[3].P0.y)/2;
				for (int i = 0; i < wood.size(); i++) {
					wood[i].Rotate(30, Point(x,y));
					wood[i].Translate(10, 0);
				}
			}
			
			// kalo udah keluar layar, kita ke atasin lagi
			if (wood[0].P0.x > 640 || wood[1].P0.x > 640 || wood[2].P0.x > 640 || wood[3].P0.x > 640) {
				wood.clear();
				
				wood.push_back(Line(Point(318, 218), Point(318, 220), BROWN));
				wood.push_back(Line(Point(318, 220), Point(322, 220), BROWN));
				wood.push_back(Line(Point(322, 220), Point(322, 218), BROWN));
				wood.push_back(Line(Point(322, 218), Point(318, 218), BROWN));
				
				lane = rand() % 3;
				
				if (lane == 0) {
					for (int i = 0; i < wood.size(); i++) {
						wood[i].Translate(-5, 0);
					}
				} else if (lane == 2) {
					for (int i = 0; i < wood.size(); i++) {
						wood[i].Translate(5, 0);
					}
				}
			}
		} else if (type == STONE) {
			if (IsStoneFront()) {
				for (int i = 0; i < stone.size(); i++) {
					stone[i].Scale(1.075, Point(320, 210));
				}
			} else {
				double x = (stone[0].P0.x + stone[1].P0.x + stone[2].P0.x)/3;
				double y = (stone[0].P0.y + stone[1].P0.y + stone[2].P0.y)/3;
				for (int i = 0; i < stone.size(); i++) {
					stone[i].Rotate(30, Point(x,y));
					stone[i].Translate(10, 0);
				}
			}
			
			if (stone[0].P0.x > 640 || stone[1].P0.x > 640 || stone[2].P0.x > 640) {
				stone.clear();
				
				stone.push_back(Line(Point(320, 219), Point(319, 220), BROWN));
				stone.push_back(Line(Point(319, 220), Point(321, 220), BROWN));
				stone.push_back(Line(Point(321, 220), Point(320, 219), BROWN));
				
				lane = rand() % 3;
				
				if (lane == 0) {
					for (int i = 0; i < stone.size(); i++) {
						stone[i].Translate(-5, 0);
					}
				} else if (lane == 2) {
					for (int i = 0; i < stone.size(); i++) {
						stone[i].Translate(5, 0);
					}
				}
			}
		}
	}
	
	if (counter == 0) {
		counter = 2;
	}
	
	counter--;
}

bool Barrier::IsWheelFront() {
	return (wheel[0].C.y + wheel[0].R < 480);
}

bool Barrier::IsWoodFront() {
	return (wood[1].P0.y < 480 && wood[1].P1.y < 480 && wood[3].P0.y < 480 && wood[3].P1.y < 480);
}

bool Barrier::IsStoneFront() {
	return (stone[0].P0.y < 480 && stone[1].P0.y < 480 && stone[2].P0.y < 480);
}