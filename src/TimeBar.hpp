#ifndef TIMEBAR_HPP
#define TIMEBAR_HPP

#include "Canvas.hpp"
#include "Drawable.hpp"
#include "Point.hpp"
#include "Stroke.hpp"
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
		Point position;
		std::vector<Line> strokes;
		
		int color_fill;
		int color_border;
		
		int counter;
};

#endif