#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include "Circle.hpp"
#include "Point.hpp"
#include "Canvas.hpp"

enum barrierType {WHEEL, WOOD, STONE};

class Barrier {
	public:
		Circle wheel;
		Circle wood;
		Circle stone;
		
		Point position;
		int lane;
		int type;
		
		Barrier(int type);
		void Draw(Canvas&);
		void Update();
};

#endif