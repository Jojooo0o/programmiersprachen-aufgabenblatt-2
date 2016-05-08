#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "window.hpp"

class Circle{
	
public:

	Circle();
	Circle(float, float, float, Color);
	float get_r() const ;
	float get_centerx() const ;
	float get_centery() const ;
	float circumference() const ;

	void draw_circle(Window& win);
	void draw_circle(Window& win, Color const& clr);

	bool is_inside(float, float);

private:
	float r_;
	float centerx_;
	float centery_;
	Color c_;
};

#endif