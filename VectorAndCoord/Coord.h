// Fait par Mathias Lavoie : LAVM19040400
#pragma once

#include <array>

using namespace std;

template <typename T, int S> 
class Coord
{
private:
	array<T, S> values;
public:
	Coord(const array<T, S>&);
	Coord(const Coord&);

	void operator=(const Coord&);
	Coord operator+(const Coord&) const;
	T operator*(const Coord&) const;

	const array<T, S>& get_values() const;

	template <typename T, int S1, int S2>
	friend Coord<T, S1 + S2> concat(const Coord<T, S1>&, const Coord<T, S2>&);
};

template <typename T, int S>
Coord<T, S>::Coord(const array<T, S>& values) : values(values) {}

template <typename T, int S>
Coord<T, S>::Coord(const Coord& other) : values(other.values) {}

template <typename T, int S>
void Coord<T, S>::operator=(const Coord& other) { values = other.values; }

template <typename T, int S>
Coord<T, S> Coord<T, S>::operator+(const Coord& other) const {
	array<T, S> result;

	for (int cpt = 0; cpt < S; cpt++)
	{
		result[cpt] = (values[cpt] + other.get_values()[cpt]);
	}

	return Coord(result);
}

template <typename T, int S>
T Coord<T, S>::operator*(const Coord& other) const {
	T result;

	for (int cpt = 0; cpt < S; cpt++)
	{
		result = result + (values[cpt] * other.get_values()[cpt]);
	}

	return result;
}

template <typename T, int S>
const array<T, S>& Coord<T, S>::get_values() const { return values; }

template <typename T, int S1, int S2>
Coord<T, S1 + S2> concat(const Coord<T, S1>& coord1, const Coord<T, S2>& coord2) {
	array<T, S1 + S2> result;

	for (int cpt = 0; cpt < S1; cpt++)
	{
		result[cpt] = coord1.get_values()[cpt];
	}

	for (int cpt = 0; cpt < S2; cpt++)
	{
		result[S1 + cpt] = coord2.get_values()[cpt];
	}

	return Coord<T, S1 + S2>(result);
}