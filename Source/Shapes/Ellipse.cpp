#include "Ashkal/Shapes/Ellipse.hpp"

using namespace Ashkal;

Ellipse::Ellipse()
  : Ellipse(0, 0) {}

Ellipse::Ellipse(double width, double height)
  : m_major_radius(width),
    m_minor_radius(height) {}

double Ellipse::get_major_radius() const {
  return m_major_radius;
}

double Ellipse::get_minor_radius() const {
  return m_minor_radius;
}

void Ellipse::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Ellipse Ashkal::make_circle(double radius) {
  return Ellipse(2 * radius, 2 * radius);
}
