#ifndef ASHKAL_ELLIPSE_HPP
#define ASHKAL_ELLIPSE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Ellipse : public Shape {
    public:

      //! Constructs an Ellipse with radius 0.
      Ellipse();

      //! Constructs an Ellipse with a defined major and minor radius.
      /*
        \param major The major radius of the Ellipse.
        \param minor The minor radius of the Ellipse.
      */
      Ellipse(double major, double minor);

      double get_major_radius() const;

      double get_minor_radius() const;

      void accept(ShapeVisitor& visitor) const override;

    private:
      double m_major_radius;
      double m_minor_radius;
  };

  Ellipse make_circle(double radius);
}

#endif
