#include "Ashkal/Ashkal/Point.hpp"

using namespace Ashkal;

Point Ashkal::operator *(const Matrix& mat, const Point& p) {
  return Point{p.x * mat.get(0, 0) + p.x * mat.get(0, 1) + mat.get(0, 2),
    p.y * mat.get(1, 0) + p.y * mat.get(1, 1) + mat.get(1, 2)};
}
