#ifndef Notification_HPP
#define Notification_HPP

#include "Polygon.hpp"

class Notification: public Drawable {
    private:
        Polygon2 * pol;
        int drawApa;
        
	public:
		//ctor-dtor
		Notification();
		virtual ~Notification();
		//method
        void Draw(Canvas& /* canvas */);
		//void Update();
        void drawYou();
        void drawWin();
        void drawLose();
};
#endif