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
	road.push_back(Line(Point(10,465), Point(40,465), road_border));
	road.push_back(Line(Point(40,465), Point(40, 15), road_border));
	road.push_back(Line(Point(40, 15), Point(10, 15), road_border));
	// jangan lupa garis putus2nya
	road.push_back(Line(Point(20, 15), Point(20,465), road_border));
	road.push_back(Line(Point(30, 15), Point(30,465), road_border));
	
	// membuat mobil: badannya
	car.push_back(Line(Point(21,465), Point(21,475), car_border));
	car.push_back(Line(Point(21,475), Point(29,475), car_border));
	car.push_back(Line(Point(29,475), Point(29,465), car_border));
	car.push_back(Line(Point(29,465), Point(21,465), car_border));
	// dan rodanya
	car.push_back(Line(Point(20,467), Point(20,469), car_border));
	car.push_back(Line(Point(20,471), Point(20,473), car_border));
	car.push_back(Line(Point(30,467), Point(30,469), car_border));
	car.push_back(Line(Point(30,471), Point(30,473), car_border));
	
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
		if (car[4].P0.x >= 20) {
			for (int i = 0; i < car.size(); i++) {
				car[i].Translate(10*x,0);
			}
		}
	} else { // ke kanan jangan ampe kelewatan
		if (car[6].P0.x <= 30) {
			for (int i = 0; i < car.size(); i++) {
				car[i].Translate(10*x,0);
			}
		}
	}
}