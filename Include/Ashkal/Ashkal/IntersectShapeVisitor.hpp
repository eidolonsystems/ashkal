#ifndef ASHKAL_INTERSECT_SHAPE_VISITOR_HPP
#define ASHKAL_INTERSECT_SHAPE_VISITOR_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shapes.hpp"

namespace Ashkal {

  //! Determines if a shape is intersecting a Rectangle.
  /*
    \param a The Rectangle used for comparison.
    \param p1 The position of the Rectangle.
    \param b The Shape to check for intersection with the Rectangle.
    \param p2 The position of the Shape.
  */
  bool intersects(const Square& a, const Point& p1, const Shape& b,
    const Point& p2);
}

#endif
