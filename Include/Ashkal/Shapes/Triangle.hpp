#ifndef ASHKAL_TRIANGLE_HPP
#define ASHKAL_TRIANGLE_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Triangle : public Shape {
    public:

      //! Constructs a Triangle with all points at the origin.
      Triangle();

      //! Constructs a Triangle with defined points.
      /*
        \param point1 First vertex of the triangle.
        \param point2 Second vertex of the triangle.
        \param point3 Third vertex of the triangle.
      */
      Triangle(const Point& point1, const Point& point2, const Point& point3);

      const std::array<Point, 3>& get_points() const;

      void accept(ShapeVisitor& visitor) const override;

    private:
      std::array<Point, 3> m_points;
  };
}

#endif
