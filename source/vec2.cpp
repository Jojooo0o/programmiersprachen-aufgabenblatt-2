#include <iostream>
#include "vec2.hpp"

Vec2::Vec2() : //default constructor
	x{0},
	y{0} {}

Vec2::Vec2(float a, float b) :
	x{a},
	y{b} {}

Vec2& Vec2::operator += (Vec2 const& v)
{
	x += v.x;
	y += v.y;

	return *this;
}
Vec2& Vec2::operator -= (Vec2 const& v)
{
	x-= v.x;
	y-= v.y;

	return *this;
}
Vec2& Vec2::operator *= (float v)
{
	x *= v;
	y *= v;

	return *this;
}
Vec2& Vec2::operator / (float v)
{
	x = x / v;
	y = y / v;

	return *this;
}

Vec2 operator + (Vec2 const& u, Vec2 const& v)
{
	Vec2 a;
	a.x = u.x + v.x;
	a.y = u.y + v.y;

	return a;
}
Vec2 operator - (Vec2 const& u, Vec2 const& v);
{
	Vec2 a;
	a.x = u.x - v.x;
	a.y = u.y - v.y;

	return a;
}
Vec2 operator * (Vec2 const& v, float s);
{
	Vec2 a;
	a.x = v.x * s;
	a.y = v.y * s;

	return a;
}
Vec2 operator / (Vec2 const& v, float s);
{
	Vec2 a;
	a.x = v.x / s;
	a.y = v.y / s;

	return a;
}
Vec2 operator * (float s, Vec2 const& v);
{
	Vec2 a;
	a.x = s * v.x;
	a.y = s * v.y;

	return a;
}
//Destructor gibt den Speicherplatz der für ein Objekt reserviert wurde wieder frei.