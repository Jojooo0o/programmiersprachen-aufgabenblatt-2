#include "window.hpp"
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(0.1f*t)};
    float y2{0.5f + 0.5f * std::cos(0.1f*t)};

    float x3{0.5f + 0.5f * std::sin(t-1.f)};
    float y3{0.5f + 0.5f * std::cos(t-1.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);






    std::vector<Circle> circles = {};
    std::vector<Rectangle> rectangles {};

    circles.push_back({2.0f, 0.5f, 0.5f, {1.0f, 0.0f, 0.0f}});
    circles.push_back({2.0f, 0.45f, 0.45f, {1.0f, 0.0f, 0.0f}});

    rectangles.push_back({3.0f, 2.0f, 0.1f, 0.1f ,{1.0f, 0.0f, 0.0f}});
    rectangles.push_back({3.0f, 2.5f, 0.4f, 0.4f ,{0.0f, 1.0f, 1.0f}});

    for(Rectangle n : rectangles) {
        n.draw_rectangle(win);
        if (n.is_inside(m.first, m.second))
        {
            n.draw_rectangle(win,{0.0f, 0.0f, 1.0f});
        }
    }

    for(Circle n : circles) {
        n.draw_circle(win);
        if (n.is_inside(m.first, m.second))
        {
            n.draw_circle(win,{0.0f, 0.0f, 1.0f});
        }
    }


    win.update();

    }

  return 0;
}
