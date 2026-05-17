#pragma once

#include "cmath"

struct Vector2D
{
	double x{};
	double y{};

	double modulo() const; //modulo del vector
	double argumento() const; //argumento del vector
	Vector2D unitario() const; //devuelve un vector unitario
	Vector2D operator - (const Vector2D&) const; //resta de vectores
	Vector2D operator + (const Vector2D&) const; //suma de vectores
	Vector2D& operator += (const Vector2D&); //suma de vectores
	Vector2D operator *(double) const; // producto por un escalar
};

inline double Vector2D::modulo() const
{
	return sqrt(x * x + y * y);
}

inline Vector2D Vector2D::unitario() const
{
	auto mod = modulo();
	if (mod > 0.00001) return { x / mod, y / mod };
	return { x,y };
}

inline double Vector2D::argumento() const
{
	return atan2(y, x);
}

inline Vector2D Vector2D::operator - (const Vector2D &v) const
{
	return { x - v.x , y - v.y };
}

inline Vector2D Vector2D::operator + (const Vector2D &v) const
{
	return { x + v.x , y + v.y };
}

inline Vector2D& Vector2D::operator += (const Vector2D &v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vector2D Vector2D::operator *(double a) const
{
	return { a * x, a * y };
}

inline Vector2D operator * (double f, const Vector2D &v) { return v * f; }