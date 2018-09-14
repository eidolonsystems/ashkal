#include "Ashkal/Shapes/Circle.hpp"

using namespace Ashkal;

Circle::Circle() {
  m_radius = 0;
}

Circle::Circle(int radius)
  : m_radius(radius) {}

int Circle::get_radius() const {
  return m_radius;
}
