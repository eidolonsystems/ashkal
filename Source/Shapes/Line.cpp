#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Ashkal/Math.hpp"

using namespace Ashkal;

void Line::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Line Ashkal::make_line(const Point& p1, const Point& p2) {
  auto l = Line();
  auto length = std::sqrt(std::pow(std::abs(p1.x - p2.x), 2) +
    std::pow(std::abs(p1.y - p2.y), 2));
  auto mid_point = Point{(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
  auto slope = (p2.y - p1.y) / (p2.x - p1.x);
  auto angle = std::atan(std::abs((slope - 1) / (1 + slope)));
  l.transform(translate(mid_point.x, mid_point.y) *
    scale(length / std::sqrt(2)) * rotate(-angle));
  return l;
}
