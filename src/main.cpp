//Compilar = g++ main.cpp -lSDL2 -std=c++20 -o pixel
#include "screen.h"
#include <numeric>

struct vec3
{
  float x, y, z;
};

void rotate(vec3& point, )
{

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

  for(int i = 0; i < 100; i++)
  {
    screen.pixel(rand()%640, rand()%480);
  }

  line(screen, 100, 100, 200, 100);
  line(screen, 200, 100, 200, 200);
  line(screen, 200, 200, 100, 200);
  line(screen, 100, 200, 100, 100);

  while(true)
  {
    screen.show();
    screen.input();
  }
}