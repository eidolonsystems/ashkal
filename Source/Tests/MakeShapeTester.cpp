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
  auto inverse = invert(line.get_transformation());
  auto p1_mat = Matrix(
    {p1.x, 0, 0},
    {p1.y, 0, 0},
    {1, 0, 0});
  auto a = inverse * p1_mat;
  REQUIRE(invert(line.get_transformation()) == inverse * p1_mat);
  auto p3 = Point{0, 0};
  auto p4 = Point{0, 10};
}
