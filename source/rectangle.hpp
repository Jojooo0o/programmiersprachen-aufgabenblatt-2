#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
	
public:

	Rectangle();
	Rectangle(float,float, float, float, Color const&);
	float get_h() const;
	float get_w() const;
	float get_x() const;
	float get_y() const;
	float circumference() const;

	void draw_rectangle(Window& win);
	void draw_rectangle(Window& win, Color const& clr);

	bool is_inside(float, float);


private:
	float h_;
	float w_;
	float x_; // unterer linker eckpunkt
	float y_;
	Color c_;
};


#endif