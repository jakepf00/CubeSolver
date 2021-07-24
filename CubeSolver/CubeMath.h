#pragma once

class Point {
public:
	Point();
	Point(int x, int y, int z);
	int dot(Point p); // returns dot product
	int x;
	int y;
	int z;
	Point operator+(const Point& p);
};
class Matrix {
public:
	Matrix();
};

