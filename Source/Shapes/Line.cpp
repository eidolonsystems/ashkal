#include "Ashkal/Shapes/Line.hpp"
#include <climits>

using namespace Ashkal;

Line::Line() {
  Point point;
  point.x = 0;
  point.y = 0;
  m_point = point;
}

Line::Line(const Point& point)
  : m_point(point) {}

Point Line::get_point() const {
  return m_point;
}
