#include <iostream>
#include "Line.hpp"
#include "TimeBar.hpp"
using namespace std;

TimeBar::TimeBar() {
	position = Point(10,10);
	
	// warna jalan dan mobil
	road_fill = DARKGRAY;
	road_border = LIGHTGRAY;
	
	car_fill = CYAN;
	car_border = BLUE;
	
	isTimeUp = false;
	
	// membuat time bar untuk lifetime 30 detik
	road.push_back(Line(Point(10, 15), Point(10,465), road_border));
	road.push_back(Line(Point(10,465), Point(45,465), road_border));
	road.push_back(Line(Point(45,465), Point(45, 15), road_border));
	road.push_back(Line(Point(45, 15), Point(10, 15), road_border));
	// jangan lupa garis putus2nya
	road.push_back(Line(Point(28, 15), Point(28,465), road_border));
	
	// membuat mobil: badannya
	car.push_back(Line(Point(23,465), Point(23,475), car_border));
	car.push_back(Line(Point(23,475), Point(31,475), car_border));
	car.push_back(Line(Point(31,475), Point(31,465), car_border));
	car.push_back(Line(Point(31,465), Point(23,465), car_border));
	// dan rodanya
	car.push_back(Line(Point(22,467), Point(22,469), car_border));
	car.push_back(Line(Point(22,471), Point(22,473), car_border));
	car.push_back(Line(Point(32,467), Point(32,469), car_border));
	car.push_back(Line(Point(32,471), Point(32,473), car_border));
	
	// inisiasi Timer
	counter = 29;
}

TimeBar::~TimeBar() {}

void TimeBar::Update() {
	// majuin mobil sejauh 1 pixel setiap 1/15 detik
	if (counter % 2 == 0) {
		for (int i = 0; i < car.size(); i++) {
			car[i].Translate(0,-1);
		}
	}

	if (counter == 0) {
		counter = 2;
	}
	
	counter--;
	
	// mobilnya udah sampe finish
	if (car[0].P0.y == 15) {
		isTimeUp = true;
	}
}

void TimeBar::Draw(Canvas& canvas) {
	// warnain jalanan
	for (int i = 0; i < 4; i++) {
		canvas.DrawLine(road[i], road_border);
	}
	
	canvas.FillRect(road[1].P0.x, road[0].P1.y, road[1].P1.x, road[0].P0.y, road_fill);
	
	// dan garis putus2nya
	for (int i = 4; i < 6; i++) {
		canvas.DrawDash(road[i], 10, 5, road_border);
	}
	
	// warnain mobil
	for (int i = 0; i < car.size(); i++) {
		canvas.DrawLine(car[i], car_border);
	}
	
	canvas.FillRect(car[1].P0.x, car[0].P1.y, car[1].P1.x, car[0].P0.y, car_fill);
}

bool TimeBar::IsTimeUp() {
	return isTimeUp;
}

void TimeBar::Move(int x) {
	if (x == -1) { // ke kiri jangan ampe kelewatan
		if (car[4].P0.x - 2 >= 10) {
			for (int i = 0; i < car.size(); i++) {
				car[i].Translate(-2,0);
			}
		}
	} else { // ke kanan jangan ampe kelewatan
		if (car[4].P0.x + 2 <= 34) {
			for (int i = 0; i < car.size(); i++) {
				car[i].Translate(2,0);
			}
		}
	}
}