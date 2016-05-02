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
//Destructor gibt den Speicherplatz der für ein Objekt reserviert wurde wieder frei.