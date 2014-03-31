#ifndef CAR_HPP
#define CAR_HPP

#include "Circle.hpp"
#include "Line.hpp"
#include "Drawable.hpp"
#include "Polygon.hpp"

#include <vector>

using namespace std;

class Car: public Drawable {
	public:
		// ctor-dtor-cctor
		Car();
		~Car();
		Car(const Car&);
		Car& operator=(const Car&);
		
		//methods
		void Draw(Canvas&);
		void Update();
		void Move(int);
		
	private:
		vector <Polygon> carshape;
		Point position;

};
#endif