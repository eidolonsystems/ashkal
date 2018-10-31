#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Tests/TestUtility.hpp"

using namespace Ashkal;

namespace {
  bool check_point(const Point& p, const Point& ref_pt1,
      const Point& ref_pt2) {
    return (equals(p.x, ref_pt1.x) && equals(p.y, ref_pt1.y)) ||
      (equals(p.x, ref_pt2.x) && equals(p.y, ref_pt2.y));
  }

  bool check_line(const Point& p1, const Point& p2, const Line& line) {
    auto tp1 = line.get_transformation() * Point{0.5, 0.5};
    auto tp2 = line.get_transformation() * Point{-0.5, -0.5};
    return check_point(tp1, p1, p2) && check_point(tp2, p1, p2);
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

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line",
    "[make_line]") {
  auto p1 = Point{2, 2};
  auto p2 = Point{4, 5};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line 2",
    "[make_line]") {
  auto p1 = Point{10, 5};
  auto p2 = Point{-2, 2};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line 3",
    "[make_line]") {
  auto p1 = Point{3, 3};
  auto p2 = Point{3.5, 85};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line 4",
    "[make_line]") {
  auto p1 = Point{3, 3};
  auto p2 = Point{-2, -85};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line 5",
    "[make_line]") {
  auto p1 = Point{1, 1};
  auto p2 = Point{20, 2};
  auto line = make_line(p1, p2);
  REQUIRE(check_line(p1, p2, line));
}

TEST_CASE("Testing Creation of Rotated, Translated, and Scaled Line 6",
    "[make_line]") {
  auto p1 = Point{1, 1};
  auto p2 = Point{-1, 85};
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
