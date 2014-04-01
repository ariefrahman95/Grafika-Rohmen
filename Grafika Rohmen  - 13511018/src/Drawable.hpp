#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Canvas.hpp"

// abstract class for a drawable thing using a canvas
class Drawable {
	public:
		virtual void Draw( Canvas& canvas ) = 0;
};

#endif