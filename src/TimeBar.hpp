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

	protected:
		TimeBar(const TimeBar&);
		TimeBar& operator=(const TimeBar&);
	
	private:
		std::vector<Line> lines;
		std::vector<Circle> circles;
		
		Point position;
		
		int color_fill;
		int color_border;
		
		int counter;
};

#endif