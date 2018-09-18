#include "Ashkal/Shapes/Line.hpp"
#include <climits>

using namespace Ashkal;

Line::Line()
  : Line({0, 0}) {}

Line::Line(const Point& point)
  : m_point(point) {}

Point Line::get_point() const {
  return m_point;
}

void Line::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
