#include "Ashkal/Shapes/Triangle.hpp"

using namespace std;
using namespace Ashkal;

Triangle::Triangle()
  : Triangle({0, 0}, {0, 0}, {0, 0}) {}

Triangle::Triangle(const Point& point1, const Point& point2,
    const Point& point3)
    : m_points({point1, point2, point3}) {}

const array<Point, 3>& Triangle::get_points() const {
  return m_points;
}

void Triangle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
