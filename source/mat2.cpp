#include <iostream>
#include <cmath>
#include "mat2.hpp"
#include "vec2.hpp"

Mat2::Mat2() :
	a1_1{1},
	a1_2{0},
	a2_1{0},
	a2_2{1}{}

Mat2::Mat2(float a, float b, float c, float d) :
	a1_1{a},
	a1_2{b},
	a2_1{c},
	a2_2{d}{}


Mat2& Mat2:: operator *=(Mat2 const& m)
{

	float a = a1_1 * m.a1_1 + a1_2 * m.a2_1;
	float b = a1_1 * m.a1_2 + a1_2 * m.a2_2;
	float c = a2_1 * m.a1_1 + a2_2 * m.a2_1;
	float d = a2_1 * m.a1_2 + a2_2 * m.a2_2;

	a1_1 = a;
	a1_2 = b;
	a2_1 = c;
	a2_2 = d;

	return *this;
}

Mat2 operator * (Mat2 const& m1, Mat2 const& m2)
{
	Mat2 m;

	float a = m1.a1_1 * m2.a1_1 + m1.a1_2 * m2.a2_1;
	float b = m1.a1_1 * m2.a1_2 + m1.a1_2 * m2.a2_2;
	float c = m1.a2_1 * m2.a1_1 + m1.a2_2 * m2.a2_1;
	float d = m1.a2_1 * m2.a1_2 + m1.a2_2 * m2.a2_2;

	m.a1_1 = a;
	m.a1_2 = b;
	m.a2_1 = c;
	m.a2_2 = d;

	return m;
}

Vec2 operator * (Mat2 const& m, Vec2 const& v)
{
	Vec2 w;

	float a = m.a1_1 * v.x + m.a1_2 * v.y;
	float b = m.a2_1 * v.x + m.a2_2 * v.y;
	w.x = a;
	w.y = b;

	return w;
}

Vec2 operator * (Vec2 const& v, Mat2 const& m)
{
	Vec2 w;
	//eigentlich nicht mathematisch korrekt
	float a = m.a1_1 * v.x + m.a1_2 * v.y;
	float b = m.a2_1 * v.x + m.a2_2 * v.y;
	w.x = a;
	w.y = b;

	return w;
}

float Mat2::det () const
{
	return a1_1 * a2_2 - a1_2 * a2_1;
}

Mat2 inverse(Mat2 const& m)
{
	if(m.det()== 0){
		return Mat2{0,0,0,0};
	}else{
		float z = 1 / m.det();

		float a = m.a2_2 * z;
		float b = -m.a1_2 * z;
		float c = -m.a2_1 * z;
		float d = m.a1_1 * z;
		return Mat2{a,b,c,d};
	}
}

Mat2 transponse(Mat2 const& m)
{
	float a = m.a1_1;
	float b = m.a2_1;
	float c = m.a1_2;
	float d = m.a2_2;

	return Mat2{a,b,c,d};
}

Mat2 make_rotation_mat2(float phi)
{

	float a = cos(phi);
	float b = -sin(phi);
	float c = sin(phi);
	float d = cos(phi);

	return Mat2{a,b,c,d};
}