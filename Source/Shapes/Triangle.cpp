#include "Ashkal/Shapes/Triangle.hpp"

using namespace std;
using namespace Ashkal;

Triangle::Triangle()
  : Triangle({0, 0}, {0, 0}, {0, 0}) {}

Triangle::Triangle(const Point& point1, const Point& point2,
    const Point& point3)
    : m_point1(point1),
      m_point2(point2),
      m_point3(point3) {}

array<Point, 3> Triangle::get_points() const {
  return array<Point, 3>({m_point1, m_point2, m_point3});
}

void Triangle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
