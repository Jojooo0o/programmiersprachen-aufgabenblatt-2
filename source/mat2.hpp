#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

//Mat2 class definition
class Mat2
{
public:

	//constructor
	Mat2();
	Mat2(float, float, float, float);
	//function
	float det() const;
	//operator
	Mat2& operator *= (Mat2 const& m);

	float a1_1;
	float a1_2;
	float a2_1;
	float a2_2;



};

Mat2 operator * (Mat2 const& m1, Mat2 const& m2);
Vec2 operator * (Mat2 const& m, Vec2 const& v);
Vec2 operator * (Vec2 const& v, Mat2 const& m);


#endif 