#ifndef ASHKAL_ELLIPSE_HPP
#define ASHKAL_ELLIPSE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Ellipse : public Shape {
    public:

      //! Constructs a Ellipse with width and height of 0.
      Ellipse();

      //! Constructs a Ellipse with a defined width and height.
      /*
        \param width The width of the Ellipse.
        \param height The height of the Ellipse.
      */
      Ellipse(double width, double height);

      double get_width() const;

      double get_height() const;

      void accept(ShapeVisitor& visitor) const override;

    private:
      double m_width;
      double m_height;
  };
}

#endif
