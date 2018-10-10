#include "Ashkal/Shapes/Ellipse.hpp"

using namespace Ashkal;

Ellipse::Ellipse()
  : Ellipse(0, 0) {}

Ellipse::Ellipse(double width, double height)
  : m_x_radius(width),
    m_y_radius(height) {}

double Ellipse::get_x_radius() const {
  return m_x_radius;
}

double Ellipse::get_y_radius() const {
  return m_y_radius;
}

void Ellipse::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Ellipse Ashkal::make_circle(double radius) {
  return Ellipse(2 * radius, 2 * radius);
}
