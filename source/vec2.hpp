#ifndef VEC2_HPP
#define VEC2_HPP

//Vec2 class definition
class Vec2
{
public:
	//constructors
	Vec2();
	Vec2(float, float);
	//operatoren
	Vec2& operator += (Vec2 const&);
	Vec2& operator -= (Vec2 const&);
	Vec2& operator *= (float);
	Vec2& operator / (float);

	float x;
	float y;
};
	//operatoren ! in class
	Vec2 operator + (Vec2 const& u, Vec2 const& v);
	Vec2 operator - (Vec2 const& u, Vec2 const& v);
	Vec2 operator * (Vec2 const& v, float s);
	Vec2 operator / (Vec2 const& v, float s);
	Vec2 operator * (float s, Vec2 const& v);


#endif //VEC2_HPP