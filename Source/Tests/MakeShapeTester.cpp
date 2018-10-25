#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Tests/TestUtility.hpp"

using namespace Ashkal;

namespace {
  Point get_transformed_point(const Point& p, const Matrix& transform) {
    return Point{-0.5 * transform.get(0, 0) + -0.5 *
      transform.get(0, 1) + transform.get(0, 2),
      -0.5 * transform.get(1, 0) + -0.5 * transform.get(1, 1) +
      transform.get(1, 2)};
  }

  bool check_line(const Point& p1, const Point& p2, const Line& line) {
    auto p = get_transformed_point(p1, line.get_transformation());
    if(p.x == p1.x) {
      if(equals(p.y, p1.y)) {
        return true;
      }
      return false;
    } else {
      if(equals(p.x, p2.x) && equals(p.y, p2.y)) {
        return true;
      }
      return false;
    }
  }
}

TEST_CASE("Testing Creation of Line from Points", "[make_line]") {
  auto p1 = Point{-2, 2};
  auto p2 = Point{2, -2};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}
