#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Ashkal/Math.hpp"

using namespace Ashkal;

void Line::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Line Ashkal::make_line(const Point& p1, const Point& p2) {
  auto l = Line();
  auto length = distance(p1, p2);
  auto mid_point = midpoint(p1, p2);
  auto s = slope(p1, p2);
  auto a = line_angle(s);
  if(std::abs(s) > 1) {
    a = -a;
  }
  l.transform(translate(mid_point.x, mid_point.y) *
    scale(length / std::sqrt(2)) * rotate(a));
  return l;
}

double Ashkal::slope(const Point& p1, const Point& p2) {
  return (p2.y - p1.y) / (p2.x - p1.x);
}

double Ashkal::line_angle(double slope) {
  return std::atan(std::abs((slope - 1) / (1 + slope)));
}
