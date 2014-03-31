#include "Barrier.hpp"

Barrier::Barrier(int type) {
	if(type == WHEEL) {
		Point p(320, 0);
		wheel.C = p;
		wheel.R = 1;
		wheel.color = 255;
	} else if(type == WOOD) {
		Point p(320, 0);
		wheel.C = p;
		wheel.R = 1;
		wheel.color = 128;
	} else if(type == STONE) {
	Point p(320, 0);
		wheel.C = p;
		wheel.R = 1;
		wheel.color = 64;
	}
	this->type = type;
}

void Barrier::Draw(Canvas& canvas) {
	if(type == WHEEL)
		canvas.DrawCircle(wheel);
	else if(type == WOOD);
	else if(type == STONE);
}

void Barrier::Update() {
	if(type == WHEEL) {
		if(wheel.R <= 75) wheel.R++;
		wheel.C.x--;
		wheel.C.y++;
	} else if(type == WOOD) {
		if(wheel.R <= 75) wheel.R++;
		wheel.C.x--;
		wheel.C.y++;
	} else if(type == STONE) {
	Point p(320, 0);
		if(wheel.R <= 75) wheel.R++;
		wheel.C.x--;
		wheel.C.y++;
	}
}

