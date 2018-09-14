#ifndef ASHKAL_CIRCLE_HPP
#define ASHKAL_CIRCLE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Circle : public Shape {
    public:

      //! Constructs a Circle with radius 0.
      Circle();

      //! Constructs a Circle with a defined radius.
      /*
        \param radius The radius of the circle.
      */
      Circle(double radius);

      double get_radius() const;

    private:
      double m_radius;
  };
}

#endif
