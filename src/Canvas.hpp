#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Circle.hpp"
#include <graphics.h>
#include "Line.hpp"
#include "Point.hpp"

#define CENTERX ((getmaxx()+1)/2)
#define CENTERY ((getmaxy()+1)/2)
#define ABS(X) ((X < 0) ? -X : X)

// provides window and drawing methods
class Canvas {

	public:
		// ctor-dtor
		Canvas();
		~Canvas();
		
		// any drawing method has to be inside BeginDraw and EndDraw
		void BeginDraw();
		void EndDraw();
		
		void DrawLine(Line, int);
		//void DrawCircle(Circle, int);
		void Fill(Point, int);
		void FillFlood(Point, int, int); // only small area
		
	protected:
		// make the object non-copyable
		Canvas( const Canvas& );
		Canvas& operator = ( const Canvas& );
		
	private:
		// get the currently inactive page
		inline const int InactivePage() const;
		
		int page;
		bool drawing;
};

#endif