#ifndef ASHKAL_ELLIPSE_HPP
#define ASHKAL_ELLIPSE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a Circle.
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
