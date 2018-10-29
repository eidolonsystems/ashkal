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
  auto slope = (p1.y - p2.y) / (p1.x - p2.x);
  auto angle = PI - std::abs(atan(slope) - atan(1));
  auto a = rotate(angle);
  auto b = scale(length / std::sqrt(2));
  auto c = translate(mid_point.x, mid_point.y);
  l.transform(c * b * a);
  return l;
}
