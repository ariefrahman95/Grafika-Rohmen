#ifndef TIMEBAR_HPP
#define TIMEBAR_HPP

#include "Canvas.hpp"
#include "Drawable.hpp"
#include "Point.hpp"
#include <vector>

class TimeBar: public Drawable {
	public:
		TimeBar();
		~TimeBar();
	
		void Update();
		void Draw(Canvas&);
		
		bool IsTimeUp();
		
		void Move(int); // -1:bergerak ke kiri, 1:bergerak ke kanan

	protected:
		TimeBar(const TimeBar&);
		TimeBar& operator=(const TimeBar&);
	
	private:
		std::vector<Line> road;
		std::vector<Line> car;
		
		Point position;
		
		int road_fill;
		int road_border;
		
		int car_fill;
		int car_border;
		
		bool isTimeUp;
		
		int counter;
};

#endif