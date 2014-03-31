#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include "Line.h"
#include "Circle.h"
#include "Point.h"

enum barrierType {WHEEL, WOOD, STONE};

class Barrier : public Drawable{
	private:
		std::vector<Line> lineArr;
		std::vector<Circle> circleArr;
		Point position;
	public:
		Barrier(int type);
		void update();
};

#endif