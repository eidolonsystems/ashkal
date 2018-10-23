#include "Ashkal/Shapes/Line.hpp"

using namespace Ashkal;

void Line::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Line Ashkal::make_line(const Point& p1, const Point& p2) {
  auto l = Line();
  auto length = std::sqrt(std::pow(std::abs(p1.x - p2.x), 2) +
    std::pow(std::abs(p1.y - p2.y), 2));
  auto slope = (p1.y - p2.y) / (p1.x - p2.x);
  auto angle = (std::atan(1) * 4) - std::abs(atan(slope) - atan(1));
  l.transform(rotate(angle) * (scale(length) * translate(p1.x, p1.y)));
  return l;
}
