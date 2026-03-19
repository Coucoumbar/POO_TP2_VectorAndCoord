// Fait par Mathias Lavoie : LAVM19040400
#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator>(Point& other) const {
	return (x > other.get_x() || (x == other.get_x() && y > other.get_y()));
}

Point Point::operator+(const Point& other) const {
	Point result{ (x + other.get_x()), (y + other.get_y()) };
	return result;
}

Point Point::operator*(const Point& other) const {
	Point result{ (x * other.get_x()), (y * other.get_y()) };
	return result;
}

const int Point::get_x() const { return x; }
const int Point::get_y() const { return y; }