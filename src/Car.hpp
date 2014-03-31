#ifndef CAR_HPP
#define CAR_HPP

#include "Circle.hpp"
#include "Line.hpp"
#include <vector>

using namespace std;

class Car {
	public:
		// ctor-dtor-cctor
		Car();
		~Car();
		Car(const Car&);
		Car& operator=(const Car&);
		
		//methods
		void Update();
		void Move(int);
		
	private:
		vector <Line> lines;
		vector <Circle> circles;
		Point position;

};
#endif