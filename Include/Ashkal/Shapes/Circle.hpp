#ifndef ASHKAL_CIRCLE_HPP
#define ASHKAL_CIRCLE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a unit circle centered at the origin.
  class Circle : public Shape {
    public:

      void accept(ShapeVisitor& visitor) const override;
  };

  //! Creates an ellipse with a specified width and height.
  /*
    \param width Width of the ellipse.
    \param height Height of the ellipse.
  */
  Circle make_ellipse(double width, double height);
}

#endif
