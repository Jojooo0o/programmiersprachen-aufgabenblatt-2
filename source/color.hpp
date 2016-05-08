#ifndef COLOR_HPP
#define COLOR_HPP
#include <cassert>


struct Color{
	

	Color(float c) :
		r{c},
		g{c},
		b{c} {
			assert(c >= 0 && c <= 1);
		}

	Color(float r,float g,float b) :
		r{r},
		g{g},
		b{b} {
			assert(r >= 0 && r <= 1);
			assert(g >= 0 && g <= 1);
			assert(b >= 0 && b <= 1);
		}

	float r;
	float g;
	float b;
};

#endif