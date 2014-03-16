class Point{
	private:
		int x;
		int y;
	public:
		
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
}

class Line{
	private:
		Point p1;
		Point p2;
	public:
		Point getP1();
		Point getP2();
		void setP1(Point P);
		void setP2(Point P);
}

class Bezier{
	private:
		Point* points;
		int n;
}