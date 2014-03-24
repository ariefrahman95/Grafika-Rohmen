#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <graphics.h>

// provides window and drawing methods
class Canvas {

	public:
		// ctor-dtor
		Canvas();
		~Canvas();
		
		// any drawing method has to be inside BeginDraw and EndDraw
		void BeginDraw();
		void EndDraw();
		
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