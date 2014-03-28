#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

// abstract class for a drawable thing using a canvas
class Drawable {
	public:
		public void Draw( Canvas& canvas ) = 0;
};

#endif