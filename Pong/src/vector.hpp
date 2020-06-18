#pragma once
#include <cmath>

template <typename type>

class Vector2D
{
	public:

		type x;
		type y;

		Vector2D(type x, type y);
		Vector2D operator-(Vector2D const &object) const;
		Vector2D operator+(Vector2D const &object) const;
		Vector2D operator*(type const value) const;
		Vector2D operator/(type const value) const;
		Vector2D crossProduct(Vector2D const &object) const;
		Vector2D divisionProduct(Vector2D const &object) const;
		Vector2D normalize() const;
		float lenght() const; //need cmath

	private:
};

template <typename type>

//always befor class name add <type>(in definition)
Vector2D<type>::Vector2D(type nx, type ny)
:	x(nx),y(ny)
{}

template <typename type>

Vector2D<type> Vector2D<type>::operator+(Vector2D const &object) const
{
	return Vector2D <type>(x + object.x, y + object.y);
}

template <typename type>

Vector2D<type> Vector2D<type>::operator-(Vector2D const &object) const
{
	return Vector2D <type>(x - object.x, y - object.y);
}

template <typename type>

Vector2D<type> Vector2D<type>::operator*(type const value) const
{
	return Vector2D<type>(x * value, y * value);
}

template <typename type>

Vector2D<type> Vector2D<type>::crossProduct(Vector2D const &object) const
{
	return Vector2D <type>(x * object.x, y * object.y);
}

template <typename type>

Vector2D<type> Vector2D<type>::divisionProduct(Vector2D const &object) const
{
	return Vector2D <type>(x / object.x, y / object.y);
}

template <typename type>

Vector2D<type> Vector2D<type>::normalize() const
{
	return Vector2D <float>(x / lenght(), y / lenght());
}

template <typename type>

float Vector2D<type>::lenght() const
{
	return sqrt(x*x + y*y);
}
