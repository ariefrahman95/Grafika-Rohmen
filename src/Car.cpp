#include "Car.hpp"

Car::Car(){
	for (int i=0; i<5; i++) {
		carshape.push_back(Polygon(4)); //bentuk yang membangun mobil
	}
	//roda 1
	carshape.at(0).define(0,246,470);
	carshape.at(0).define(1,246,427);
	carshape.at(0).define(2,276,427);
	carshape.at(0).define(3,276,470);
	carshape.at(0).setColor(BLACK);
	carshape.at(0).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carshape.at(0).hubung(i, i+1);
	
	//roda 2
	carshape.at(1).define(0,364,470);
	carshape.at(1).define(1,364,427);
	carshape.at(1).define(2,394,427);
	carshape.at(1).define(3,394,470);
	carshape.at(1).setColor(BLACK);
	carshape.at(1).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carshape.at(1).hubung(i, i+1); 
	
	//badan bawah 
	carshape.at(2).define(0,256,422);
	carshape.at(2).define(1,256,384);
	carshape.at(2).define(2,384,384);
	carshape.at(2).define(3,384,422);
	carshape.at(2).setColor(BLACK);
	carshape.at(2).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carshape.at(2).hubung(i, i+1); 
		
	//badan atas 
	carshape.at(3).define(0,266,384);
	carshape.at(3).define(1,276,342);
	carshape.at(3).define(2,364,342);
	carshape.at(3).define(3,374,384);
	carshape.at(0).setColor(BLUE);
	carshape.at(3).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carshape.at(3).hubung(i, i+1); 
		
	//jendela
	carshape.at(4).define(0,276,374);
	carshape.at(4).define(1,286,352);
	carshape.at(4).define(2,354,352);
	carshape.at(4).define(3,364,374);
	carshape.at(0).setColor(LIGHTGRAY);
	carshape.at(4).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carshape.at(4).hubung(i, i+1); 
	
}
Car::~Car(){

}
Car::Car(const Car&){

}
Car& Car::operator=(const Car&){
	
	
	return *this;
}

void Car::Draw(Canvas&){

}
void Car::Update(){

}
void Car::Move(int){

}
