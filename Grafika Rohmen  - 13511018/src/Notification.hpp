#ifndef Notification_HPP
#define Notification_HPP

#include "Canvas.hpp"
#include "Drawable.hpp"
#include "Line.hpp"
#include <vector>

class Notification: public Drawable {
	public:
		//ctor-dtor
		Notification();
		~Notification();

		//method
		void Update();
		void Draw(Canvas&);
		
		std::vector<Line> lines;
		
		bool isLarger;
		int counter;
};
#endif