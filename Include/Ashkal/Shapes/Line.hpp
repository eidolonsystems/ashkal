#ifndef ASHKAL_LINE_HPP
#define ASHKAL_LINE_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a line.
  class Line : public Shape {
    public:

      void accept(ShapeVisitor& visitor) const override;
  };

  //! Creates a line with specified points.
  /*
    \param p1 The first point of the line.
    \param p2 The second point of the line.
  */
  Line make_line(const Point& p1, const Point& p2);
}

#endif
