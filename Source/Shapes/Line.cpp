#include "Ashkal/Shapes/Line.hpp"
#include <climits>

using namespace Ashkal;

Line::Line() {
  Point origin;
  origin.x = 0;
  origin.y = 0;
  m_start_point = origin;
  m_end_point = origin;
}

Line::Line(const Point& start, const Point& end) {
  m_start_point = start;
  m_end_point = end;
}

Point Line::get_start_point() const {
  return m_start_point;
}

Point Line::get_end_point() const {
  return m_end_point;
}
