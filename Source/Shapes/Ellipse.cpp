#include "Ashkal/Shapes/Ellipse.hpp"

using namespace Ashkal;

Ellipse::Ellipse()
  : Ellipse(0, 0) {}

Ellipse::Ellipse(double width, double height)
  : m_width(width),
    m_height(height) {}

double Ellipse::get_width() const {
  return m_width;
}

double Ellipse::get_height() const {
  return m_height;
}

void Ellipse::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
