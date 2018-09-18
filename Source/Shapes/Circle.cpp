#include "Ashkal/Shapes/Circle.hpp"

using namespace Ashkal;

Circle::Circle()
  : Circle(0) {}

Circle::Circle(double radius)
  : m_radius(radius) {}

double Circle::get_radius() const {
  return m_radius;
}

void Circle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
