#include "CubeMath.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
Point::Point(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
Point Point::operator+(const Point& p) {
	Point point(this->x + p.x, this->y + p.y, this->z + p.z);
	return point;
}