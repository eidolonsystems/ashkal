#ifndef ASHKAL_LINE_HPP
#define ASHKAL_LINE_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a line with enpoints at (-0.5, -0.5) and (0.5, 0.5).
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

  //! Returns the slope of a line, calculated from 2 Points.
  /*
    \param p1 The first Point.
    \param p2 The second Point.
  */
  double slope(const Point& p1, const Point& p2);

  //! Returns the angle between the line (-0.5, -0.5), (0.5, 0.5), and the
  //! line represented by the specified slope.
  /*
    \param slope The slope of the specified line.
  */
  double line_angle(double slope);
}

#endif
