#include "rectangle.hpp"
//#include "window.hpp"


Rectangle::Rectangle() :
	h_{1.0f},
	w_{2.0f},
	x_{0.0f},
	y_{0.0f},
	c_{0.0f} {}

Rectangle::Rectangle(float h, float w, float x, float y, Color const& c) :
	h_{h},
	w_{w},
	x_{x},
	y_{y},
	c_{c} {assert(w > 0.0f && h > 0.0f);}



float Rectangle::get_h() const{

	return h_;
}

float Rectangle::get_w() const {

	return w_;
}

float Rectangle::get_x() const {

	return x_;
}

float Rectangle::get_y() const {

	return y_;
}

float Rectangle::circumference() const {

	return 2 * (h_ + w_);
}

void Rectangle::draw_rectangle(Window& win){

  win.draw_line(x_, y_, x_ + (w_/10), y_, c_.r, c_.g, c_.b);
  win.draw_line(x_ + (w_/10), y_ , x_ + (w_/10), y_ + (h_/10), c_.r, c_.g, c_.b);
  win.draw_line(x_ + (w_/10), y_ + (h_/10), x_, y_ + (h_/10), c_.r, c_.g, c_.b);
  win.draw_line(x_, y_ + (h_/10), x_, y_, c_.r, c_.g, c_.b);

}

void Rectangle::draw_rectangle(Window& win, Color const& clr){

  win.draw_line(x_, y_, x_ + (w_/10), y_, clr.r, clr.g, clr.b);
  win.draw_line(x_ + (w_/10), y_ , x_ + (w_/10), y_ + (h_/10), clr.r, clr.g, clr.b);
  win.draw_line(x_ + (w_/10), y_ + (h_/10), x_, y_ + (h_/10), clr.r, clr.g, clr.b);
  win.draw_line(x_, y_ + (h_/10), x_, y_, clr.r, clr.g, clr.b);

}

bool Rectangle::is_inside(float x, float y){

	if(x > x_ && y > y_ && x < x_+ (w_ /10) && y < y_ + (h_ /10)){
		return true;
	} else {
		return false;
	}

}

