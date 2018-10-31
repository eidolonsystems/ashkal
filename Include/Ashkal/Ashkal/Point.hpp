#ifndef ASHKAL_POINT_HPP
#define ASHKAL_POINT_HPP
#include "Ashkal/Ashkal/Matrix.hpp"

namespace Ashkal {

  //! Represents a 2D point on a plane.
  struct Point {
    double x;
    double y;
  };

  //! Multiplies a Point by a Matrix.
  /*
    \param mat RHS of the multiplication.
    \param p LHS of the multiplication.
  */
  Point operator *(const Matrix& mat, const Point& p);

  //! Returns the distance between two points.
  /*
    \param p1 The first Point.
    \param p2 The second Point.
  */
  double distance(const Point& p1, const Point& p2);

  //! Returns the midpoint of two Points.
  /*
    \param p1 The first point.
    \param p2 The second point.
  */
  Point midpoint(const Point& p1, const Point& p2);
}

#endif
