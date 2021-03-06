#include "Ashkal/Ashkal/Point.hpp"

using namespace Ashkal;

Point Ashkal::operator *(const Matrix& mat, const Point& p) {
  return Point{p.x * mat.get(0, 0) + p.y * mat.get(0, 1) + mat.get(0, 2),
    p.x * mat.get(1, 0) + p.y * mat.get(1, 1) + mat.get(1, 2)};
}

double Ashkal::distance(const Point& p1, const Point& p2) {
  return std::sqrt(std::pow(std::abs(p1.x - p2.x), 2) +
    std::pow(std::abs(p1.y - p2.y), 2));
}

Point Ashkal::midpoint(const Point& p1, const Point& p2) {
  return Point{(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
}
