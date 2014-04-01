#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#include <vector>
#include <algorithm>
#include "Point.hpp"

class Transformable {

	public:
		Scale( const float scale );
		Translate( const float dx, const float dy );
		Rotate( const float angle );
		
		inline const std::vector<Point>& GetPointsConst() const;
		inline std::vector<Point>& GetPoints() const;
		
	private:
		std::vector<Point> points;
		
};

#endif