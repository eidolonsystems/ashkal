#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

TEST_CASE(R"(Testing Intersection of Rectangle and Line With Line point in
    the Rectangle)", "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{100, 100};
  auto line = Line({150, 50});
  auto line_pos = Point{0, 0};
  REQUIRE(intersects(rect, rect_pos, line, line_pos));
}

TEST_CASE(R"(Testing Intersection of Rectangle and Line With Edges of
    Rectangle)", "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{200, 200};
  auto top = Line({0, -100});
  auto top_pos = Point{250, 250};
  REQUIRE(intersects(rect, rect_pos, top, top_pos));
  auto right = Line({-100, 0});
  auto right_pos = Point{350, 150};
  REQUIRE(intersects(rect, rect_pos, right, right_pos));
  auto bottom = Line({0, 100});
  auto bottom_pos = Point{250, 50};
  REQUIRE(intersects(rect, rect_pos, bottom, bottom_pos));
  auto left = Line({100, 0});
  auto left_pos = Point{150, 150};
  REQUIRE(intersects(rect, rect_pos, left, left_pos));
}

TEST_CASE("Testing Intersection of Rectangle with Inscribed Line",
    "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{200, 200};
  auto line = Line({10, 10});
  auto line_pos = Point{225, 125};
  REQUIRE(intersects(rect, rect_pos, line, line_pos));
}

TEST_CASE(R"(Testing Intersection of Rectangle and Line When Line Coincides
    with an Edge of the Rectangle)", "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{200, 200};
  auto vertical = Line({0, 100});
  auto vert_pos = Point{200, 200};
  REQUIRE(intersects(rect, rect_pos, vertical, vert_pos));
  auto horizontal = Line({100, 0});
  auto h_pos = Point{200, 200};
  REQUIRE(intersects(rect, rect_pos, horizontal, h_pos));
}

TEST_CASE(R"(Testing Lines That Don't Intersect with a Rectangle)",
    "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{200, 200};
  auto line = Line({0, 1000});
  auto line_pos = Point{199, 0};
  REQUIRE(intersects(rect, rect_pos, line, line_pos) == false);
  line_pos = Point{301, 0};
  REQUIRE(intersects(rect, rect_pos, line, line_pos) == false);
  line = Line({1000, 0});
  line_pos = Point{0, 201};
  REQUIRE(intersects(rect, rect_pos, line, line_pos) == false);
}

TEST_CASE("Testing Intersection of Rectangles", "[intersects]") {
  auto rect1 = Rectangle(100, 100);
  auto rect1_pos = Point{200, 200};
  auto rect2 = Rectangle(100, 100);
  auto rect2_pos = Point{150, 150};
  REQUIRE(intersects(rect1, rect1_pos, rect2, rect2_pos));
  auto rect3 = Rectangle(100, 100);
  auto rect3_pos = Point{300, 200};
  REQUIRE(intersects(rect1, rect1_pos, rect3, rect3_pos));
}

TEST_CASE("Testing Intersection of Rectangle with Inscribed Rectangle",
    "[intersects]") {
  auto outer_rect = Rectangle(400, 400);
  auto outer_rect_pos = Point{100, 500};
  auto inner_rect = Rectangle(100, 100);
  auto inner_rect_pos = Point{200, 400};
  REQUIRE(intersects(outer_rect, outer_rect_pos, inner_rect, inner_rect_pos));
}

TEST_CASE(R"(Testing Intersection of Rectangle and Triangle)",
    "[intersects]") {
  auto rect = Rectangle(100, 100);
  auto rect_pos = Point{200, 200};
  auto tri = Triangle(Point{100, 150}, Point{250, 225}, Point{450, 150});
  auto tri_pos = Point{150, 300};
  REQUIRE(intersects(rect, rect_pos, tri, tri_pos));
}

TEST_CASE("Testing Intersection of Rectangle and Ellipse", "[intersects]") {
  auto rect = Rectangle(1, 1);
  auto rect_pos = Point{-1, 1};
  auto ellipse = Ellipse(1, 1);
  auto ellipse_pos = Point{0, 0};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos));
  rect = Rectangle(10, 10);
  rect_pos = Point{-10, 10};
  ellipse = Ellipse(9, 4);
  ellipse_pos = Point{0, 3};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos));
}

TEST_CASE("Testing Rectangles and Ellipses That Don't Intersect",
    "[intersects]") {
  auto rect = Rectangle(1, 1);
  auto rect_pos = Point{8, 9};
  auto ellipse = Ellipse(9, 4);
  auto ellipse_pos = Point{10, 5};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos) == false);
  rect_pos = Point{-2, 5};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos) == false);
  rect_pos = Point{1000, 1000};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos) == false);
}

TEST_CASE("Testing Rectangle inscribed in Ellipse and Vice-Versa",
    "[intersects]") {
  auto rect = Rectangle(18, 10);
  auto rect_pos = Point{2, 10};
  auto ellipse = Ellipse(5, 2);
  auto ellipse_pos = Point{10, 5};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos));
  rect = Rectangle(4, 2);
  rect_pos = Point{8, 6};
  REQUIRE(intersects(rect, rect_pos, ellipse, ellipse_pos));
}
