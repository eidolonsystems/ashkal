#ifndef ASHKAL_LINE_HPP
#define ASHKAL_LINE_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Line : public Shape {
    public:

      //! Constructs a Line with the start and end points at the origin.
      Line();

      //! Constructs a Line with defined start and end points.
      /*
        \param start The start Point of the line.
        \param end The end Point of the line.
      */
      Line(const Point& start, const Point& end);

      Point get_start_point() const;

      Point get_end_point() const;

    private:
      Point m_start_point;
      Point m_end_point;
  };
}

#endif
