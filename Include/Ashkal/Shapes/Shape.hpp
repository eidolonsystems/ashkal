#ifndef ASHKAL_SHAPE_HPP
#define ASHKAL_SHAPE_HPP
#include "Ashkal/Ashkal/ShapeVisitor.hpp"

namespace Ashkal {

  //! Represents an abstract shape.
  class Shape {
    public:

      virtual ~Shape() = default;

      virtual void accept(ShapeVisitor& visitor) const = 0;
  };
}

#endif
