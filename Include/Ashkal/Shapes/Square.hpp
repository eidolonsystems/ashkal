#ifndef ASHKAL_SQUARE_HPP
#define ASHKAL_RECTANGLE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a Square.
  class Square : public Shape {
    public:

      void accept(ShapeVisitor& visitor) const override;
  };

  //! Creates a rectangle with specified width and height.
  /*
    \param width Width of the rectangle.
    \param height Height of the rectangle.
  */
  Square make_rectangle(double width, double height);
}

#endif
