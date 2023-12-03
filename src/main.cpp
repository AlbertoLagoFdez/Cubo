//Compilar = g++ main.cpp -lSDL2 -std=c++20 -o pixel
#include "screen.h"
#include <numeric>

struct vec3
{
  float x, y, z;
};

void rotate(vec3& point, float x = 1, float y = 1, float z = 1)
{
  float rad = 0;

  rad = x;
  point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
  point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

  rad = y;
  point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
  point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

  rad = z;
  point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
  point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;


}

void line(Screen& screen, float x1, float y1, float x2, float y2)
{
  float dx = x2 - x1;
  float dy = y2 - y1;

  float length = std::sqrt(dx * dx + dy * dy);
  float angle = std::atan2(dy,dx);

  for(float i = 0; i < length; i++)
  {
    screen.pixel(
                      x1 + std::cos(angle) * i,
                      y1 + std::sin(angle) * i    );
  }
}

int main()
{
  Screen screen;

  std::vector<vec3> points {
          {100,100,100},
          {200,100,100},
          {200,200,100},
          {100,200,100},

          {100,100,200},
          {200,100,200},
          {200,200,200},
          {100,200,200}
  };


  while(true)
  {
    for(auto& p : points)
    {
      rotate(p, 0.002, 0.001, 0.004);
    }

    for(auto& p : points)
    {
      screen.pixel(p.x, p.y);
    }
    screen.show();
    screen.clear();
    screen.input();
    SDL_Delay(30);
  }
  return 0;
}