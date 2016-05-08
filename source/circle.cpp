#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle() :
	r_{1.0f},
	centerx_{0.5f},
	centery_{0.5f},
	c_{0.0f} {}

Circle::Circle(float r, float centerx, float centery, Color c) :
	r_{r},
	centerx_{centerx},
	centery_{centery},
	c_{c} {assert(r > 0);}


float Circle::get_r() const {

	return r_;
}

float Circle::get_centerx() const {

	return centerx_;
}

float Circle::get_centery() const {

	return centery_;
}

float Circle::circumference() const {
	return M_PI * r_ * 2;
}	

void Circle::draw_circle(Window& win){

  for(float i = 0.0f; i<= 2* M_PI; i += 0.05f)
	{
		win.draw_line (	(r_ / 10) * cos(i) + centerx_,
						(r_ / 10) * sin(i) + centery_,
						(r_ / 10) * cos(i + 0.05f) + centerx_,
						(r_ / 10) * sin(i + 0.05f) + centery_,
						 c_.r, c_.g, c_.b);
	}
}

void Circle::draw_circle(Window& win, Color const& clr){

  for(float i = 0.0f; i<= 2* M_PI; i += 0.05f)
	{
		win.draw_line (	(r_ / 10) * cos(i) + centerx_,
						(r_ / 10) * sin(i) + centery_,
						(r_ / 10) * cos(i + 0.05f) + centerx_,
						(r_ / 10) * sin(i + 0.05f) + centery_,
						clr.r, clr.g, clr.b);
	}
}

bool Circle::is_inside(float x, float y){

	float abstand = sqrt((x - centerx_)*(x - centerx_) + (y - centery_) * (y - centery_));

	if(abstand <= (r_ / 10)){
		return true;
	} else {
		return false;
	}

}
