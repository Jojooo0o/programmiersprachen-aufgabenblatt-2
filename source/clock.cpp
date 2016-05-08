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

    Circle circ{4.8f, 0.5f, 0.5f, {0.0f, 0.0f, 0.0f}};
    circ.draw_circle(win);

    auto t = win.get_time();
    t = (t*M_PI)/30;
    float x1{0.5f + 0.47f * std::sin(t)};
    float y1{0.5f + 0.47f * std::cos(t)};

    float x2{0.5f + 0.4f * std::sin(t/60)};
    float y2{0.5f + 0.4f * std::cos(t/60)};

    float x3{0.5f + 0.3f * std::sin(t/3600)};
    float y3{0.5f + 0.3f * std::cos(t/3600)};

    win.draw_line(0.5f, 0.5f, x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_line(0.5f, 0.5f, x2, y2, 0.0f, 0.0f, 1.0f);
    win.draw_line(0.5f, 0.5f, x3, y3, 0.0f, 0.0f, 0.0f);

    auto m = win.mouse_position();
   
    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    for(float i = 0; i<= 2*M_PI; i += (M_PI/30))
    {
        win.draw_point(0.5f + 0.45f * std::sin(i), 0.5f + 0.45f * std::cos(i), 0.0f, 0.0f, 0.0f);
    }

    win.update();

    }

  return 0;
}
