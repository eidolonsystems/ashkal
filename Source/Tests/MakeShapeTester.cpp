#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Tests/TestUtility.hpp"

using namespace Ashkal;

namespace {
  bool check_line(const Point& p1, const Point& p2, const Line& line) {
    auto tp1 = line.get_transformation() * Point{0.5, 0.5};
    auto tp2 = line.get_transformation() * Point{-0.5, -0.5};
    return equals(p1.x, tp1.x) && equals(p1.y, tp1.y) &&
      equals(p2.x, tp2.x) && equals(p2.y, tp2.y);
  }
}

TEST_CASE("Testing Creation of Rotated Line", "[make_line]") {
  auto p1 = Point{-0.5, 0.5};
  auto p2 = Point{0.5, -0.5};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Translated Line", "[make_line]") {
  auto p1 = Point{0, -0.5};
  auto p2 = Point{1, 0.5};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Scaled Line", "[make_line]") {
  auto p1 = Point{-5, -5};
  auto p2 = Point{5, 5};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated and Scaled Line", "[make_line]") {
  auto p1 = Point{-2, 2};
  auto p2 = Point{2, -2};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated and Translated Line", "[make_line]") {
  auto p1 = Point{2, 2};
  auto p2 = Point{4, 5};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line",
    "[make_line]") {
  auto p1 = Point{10, 5};
  auto p2 = Point{-2, 2};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Vertical Line", "[make_line]") {
  auto p1 = Point{0, 10};
  auto p2 = Point{0, 0};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Horizontal Line", "[make_line]") {
  auto p1 = Point{0, 0};
  auto p2 = Point{10, 0};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}
