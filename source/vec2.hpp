#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition
class Vec2
{
public:
	//constructors
	Vec2();
	Vec2(float,float);
	//operators
	Vec2& operator += (Vec2 const&);
	Vec2& operator -= (Vec2 const&);
	Vec2& operator *= (float);
	Vec2& operator / (float);

	float x;
	float y;



};

Vec2 operator +(Vec2 const&, Vec2 const&);
Vec2 operator -(Vec2 const&, Vec2 const&);
Vec2 operator *(Vec2 const&, float);
Vec2 operator /(Vec2 const&, float);
Vec2 operator *(float, Vec2 const&);

#endif