#ifndef ASHKAL_LINE_HPP
#define ASHKAL_LINE_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Represents a Line on a 2D plane.
  class Line : public Shape {
    public:

      //! Constructs a Line with the start and end points at the origin.
      Line();

      //! Constructs a Line with two points, one at the origin and another
      //! at an arbitrary point.
      /*
        \param point The point that determines the length and angle of the Line
                     relative to the origin.
      */
      Line(const Point& point);

      Point get_point() const;

    private:
      Point m_point;
  };
}

#endif
