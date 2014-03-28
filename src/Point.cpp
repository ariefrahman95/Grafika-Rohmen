#include "Point.hpp"

// swap x-y or y-x
void Point::Swap() {
	auto t = x;
		 x = y;
		 y = t;
}