#pragma once

#include "cmath"
#include <iostream>

using namespace std;

struct Vector2D
{
	double x{};
	double y{};

	double modulo() const; //modulo del vector
	double argumento() const; //argumento del vector
	bool operator ==(const Vector2D&) const; //Compara la igualdad de dos vectores
	Vector2D unitario() const; //devuelve un vector unitario
	friend ostream& operator<<(ostream& os, const Vector2D& v);
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

inline ostream& operator<<(ostream &os, const Vector2D& v)
{
	os << "(" << v.x << "," << v.y << ")";
	return os;
}

inline double Vector2D::argumento() const
{
	return atan2(y, x);
}

inline bool Vector2D::operator==(const Vector2D &v) const
{
	//Umbral para evitar problemas de exactitud
	const double umbral = 0.001;

	return (abs(x - v.x) < umbral) && (abs(y - v.y) < umbral);
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