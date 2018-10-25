#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Tests/TestUtility.hpp"

using namespace Ashkal;

TEST_CASE("Testing Creation of Line from Points", "[make_line]") {
  auto p1 = Point{-2, 2};
  auto p2 = Point{2, -2};
  auto line = make_line(p1, p2);
  auto& transformation = line.get_transformation();
  auto x = -0.5 * transformation.get(0, 0) + -0.5 * transformation.get(0, 1) +
    transformation.get(0, 2);
  auto y = -0.5 * transformation.get(1, 0) + -0.5 * transformation.get(1, 1) +
    transformation.get(1, 2);
  if(x == -2) {
    REQUIRE(y == 2);
  } else {
    REQUIRE(x == 2);
    REQUIRE(y == -2);
  }
}
