#ifndef ASHKAL_ELLIPSE_HPP
#define ASHKAL_ELLIPSE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Ellipse : public Shape {
    public:

      //! Constructs an Ellipse with radius 0.
      Ellipse();

      //! Constructs an Ellipse with a defined x and y radius.
      /*
        \param x The x radius of the Ellipse.
        \param y The y radius of the Ellipse.
      */
      Ellipse(double x, double y);

      double get_x_radius() const;

      double get_y_radius() const;

      void accept(ShapeVisitor& visitor) const override;

    private:
      double m_x_radius;
      double m_y_radius;
  };

  Ellipse make_circle(double radius);
}

#endif
