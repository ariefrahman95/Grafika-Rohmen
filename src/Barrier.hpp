#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Canvas.hpp"

enum barrierType {WHEEL, WOOD, STONE};

class Barrier {
	public:
		std::vector<Circle> wheel;
		std::vector<Line> wood;
		std::vector<Line> stone;
		
		Point position;
		int lane;
		int type;
		
		int counter;
		
		Barrier();
		Barrier(int type);
		
		void Draw(Canvas&);
		void Update();
		
		bool IsWheelFront();
		bool IsWoodFront();
		bool IsStoneFront();
};

#endif