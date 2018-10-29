#ifndef ASHKAL_POINT_HPP
#define ASHKAL_POINT_HPP
#include "Ashkal/Ashkal/Matrix.hpp"

namespace Ashkal {

  //! Represents a 2D point on a plane.
  struct Point {
    double x;
    double y;
  };

  // multiply matrix by point
  // mat * pt
  Point operator *(const Matrix& mat, const Point& p);
}

#endif
