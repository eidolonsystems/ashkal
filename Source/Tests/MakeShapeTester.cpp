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
  auto slope = (p1.y - p2.y) / (p1.x - p2.x);
  auto angle = (std::atan(1) * 4) - std::abs(atan(slope) - atan(1));
  auto result = Matrix(
    {std::cos(angle) * std::sqrt(32), std::sqrt(32), -2},
    {-std::sqrt(32), std::cos(angle) * std::sqrt(32), 2},
    {0, 0, 1});
  REQUIRE(equals(line.get_transformation(), result));
}
