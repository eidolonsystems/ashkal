#ifndef ASHKAL_INTERSECT_SHAPE_VISITOR_HPP
#define ASHKAL_INTERSECT_SHAPE_VISITOR_HPP
#include "Ashkal/Shapes/Shape.hpp"
#include "Ashkal/Shapes/Square.hpp"

namespace Ashkal {

  //! Determines if a Shape intersects with a Square.
  /*
    \param square The Square to check for intersection with the Shape.
    \param shape The Shape to check for intersection with the Square.
  */
  bool intersects(const Square& square, const Shape& shape);
}

#endif
