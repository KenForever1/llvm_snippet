// point_example.cpp

#include <string>
#include <iostream>


template <typename... Mixins>
class Point : public Mixins... {
 public:
  double x, y;
  Point() : Mixins()..., x(0.0), y(0.0) {}
  Point(double x, double y) : Mixins()..., x(x), y(y) {}
};

class Label {
 public:
  std::string label;
  Label() : label("") {}
};

class Color {
 public:
  unsigned char red = 0, green = 0, blue = 0;
};

using MyPoint = Point<Label, Color>;

int main(){
  MyPoint p(1.0, 2.0);

  p.label = "MyPoint";
  p.red = 255;
  p.green = 0;
  p.blue = 0;

  std::cout << p.label << std::endl;
  std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
  std::cout << "Color: (" << (int)p.red << ", " << (int)p.green << ", " << (int)p.blue << ")" <<std::endl;
  return 0;
}

// MyPoint
// (1, 2)
// Color: (255, 0, 0)