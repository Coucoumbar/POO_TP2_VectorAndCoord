// Fait par Mathias Lavoie : LAVM19040400
#pragma once

#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int, int);

	bool operator>(Point&) const;
	Point operator+(const Point&) const;
	Point operator*(const Point&) const;

	const int get_x() const;
	const int get_y() const;
};

