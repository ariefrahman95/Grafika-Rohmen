#ifndef CAR_HPP
#define CAR_HPP

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
		
	//private:
		vector <Polygon2> carS; //vector shape mobil
		Point position;

};
#endif