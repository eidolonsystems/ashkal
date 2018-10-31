#ifndef ASHKAL_TRIANGLE_HPP
#define ASHKAL_TRIANGLE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a right angle Triangle.
  class Triangle : public Shape {
    public:

      void accept(ShapeVisitor& visitor) const override;
  };
}

#endif
