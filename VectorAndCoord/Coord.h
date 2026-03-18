#pragma once

#include <vector>

using namespace std;

template <class Type> class Coord
{
private:

public:
	Coord(const vector<Type>&);
	Coord(const Coord&);

	Coord operator+(const Coord&);
	Type operator*(const Coord&);
};

