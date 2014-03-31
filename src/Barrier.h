#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include "Stroke.h"

enum barrierType {WHEEL, WOOD, STONE};

class Barrier {
	private:
		std::vector<Stroke> strokes;
		float position;
		barrierType type;
	public:
		Barrier(int type);
		
		void update();
		void draw();
		void translate();
		void scale();
		void rotate();
		void reflect();
		void shear();
};

#endif