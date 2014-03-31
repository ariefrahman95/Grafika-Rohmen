#include "Car.hpp"

Car::Car(){
	for (int i=0; i<5; i++) {
		carS.push_back(Polygon2(4)); //bentuk yang membangun mobil
	}
	//roda 1
	carS.at(0).define(0,246,470);
	carS.at(0).define(1,246,427);
	carS.at(0).define(2,276,427);
	carS.at(0).define(3,276,470);
	carS.at(0).setColor(DARKGRAY);
	carS.at(0).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carS.at(0).hubung(i, i+1);
	
	//roda 2
	carS.at(1).define(0,364,470);
	carS.at(1).define(1,364,427);
	carS.at(1).define(2,394,427);
	carS.at(1).define(3,394,470);
	carS.at(1).setColor(DARKGRAY);
	carS.at(1).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carS.at(1).hubung(i, i+1); 
	
	//badan bawah 
	carS.at(2).define(0,256,432);
	carS.at(2).define(1,256,384);
	carS.at(2).define(2,384,384);
	carS.at(2).define(3,384,432);
	carS.at(2).setColor(BLACK);
	carS.at(2).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carS.at(2).hubung(i, i+1); 
		
	//badan atas 
	carS.at(3).define(0,266,384);
	carS.at(3).define(1,276,342);
	carS.at(3).define(2,364,342);
	carS.at(3).define(3,374,384);
	carS.at(3).setColor(BLUE);
	carS.at(3).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carS.at(3).hubung(i, i+1); 
		
	//jendela
	carS.at(4).define(0,276,374);
	carS.at(4).define(1,281,352);
	carS.at(4).define(2,359,352);
	carS.at(4).define(3,364,374);
	carS.at(4).setColor(LIGHTGRAY);
	carS.at(4).hubung(3, 0); 
	for (int i=0; i<3; i++)
		carS.at(4).hubung(i, i+1); 
	
}
Car::~Car(){

}
Car::Car(const Car& C){
	for (int i=0; i<5; i++) {
		carS.push_back(C.carS[i]);
	}
}
Car& Car::operator=(const Car& C){
	for (int i=0; i<5; i++) {
		carS.push_back(C.carS[i]);
	}
	return *this;
}

void Car::Draw(Canvas& canvas){
	
	carS.at(0).Draw(canvas);
	canvas.FillRect(carS.at(0).getT(0).x, carS.at(0).getT(0).y, carS.at(0).getT(2).x, carS.at(0).getT(2).y, 0);
	carS.at(1).Draw(canvas);
	canvas.FillRect(carS.at(1).getT(0).x, carS.at(1).getT(0).y, carS.at(1).getT(2).x, carS.at(1).getT(2).y, 0);
	carS.at(2).Draw(canvas);
	canvas.FillRect(carS.at(2).getT(0).x, carS.at(2).getT(0).y, carS.at(2).getT(2).x, carS.at(2).getT(2).y, 1);
	carS.at(3).Draw(canvas);
	
	Point P1 = carS.at(3).getT(0); 
	canvas.Fill(P1+=Point(1,-1), 8, CYAN);
	canvas.Fill(P1+=Point(10,-1), 8, CYAN);
	
	Point P2 = carS.at(4).getT(0);
	carS.at(4).Draw(canvas);
	canvas.FillFlood(P2+=Point(1,-1), CYAN, BLUE);
	
}
void Car::Update(){

}
void Car::Move(int x){
	if (x == -1) { // Bergerak ke kiri
		if (carS.at(0).getT(0).x >= 75) {
			for (int i = 0; i < carS.size(); i++) {
				carS.at(i).translate(3,30);
			}
		}
	} else { // Bergerak ke kanan 
		if (carS.at(1).getT(3).x <= 550) {
			for (int i = 0; i < carS.size(); i++) {
				carS.at(i).translate(1,30);
			}
		}
	}

}
