#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Square.hpp"

using namespace Ashkal;

TEST_CASE("Testing Intersection of Square and Circle", "[intersects]") {
  auto circle = Circle();
  circle.transform(translate(5, 10) * rotate(0.25) * scale(2, 10));
  auto square = Square();
  square.transform(translate(2, 11) * scale(2, 5));
  REQUIRE(intersects(square, circle));
}

TEST_CASE("Testing Intersection of Square Inscribed in Circle",
    "[intersects]") {
  auto circle = Circle();
  auto square = Square();
  circle.transform(translate(-6, 10) * scale(2) * rotate(0.7854));
  square.transform(translate(-6, 10));
  REQUIRE(intersects(square, circle));
}

TEST_CASE("Testing Intersection of Square and Circle that Don't Intersect",
    "[intersects]") {
  auto circle = Circle();
  circle.transform(translate(-2, -2) * scale(2));
  auto square = Square();
  square.transform(translate(2, -2) * rotate(0.7854));
  REQUIRE(!intersects(square, circle));
}

TEST_CASE("Testing Intersection of Circle with Top of Square",
    "[intersects]") {
  auto circle = Circle();
  auto square = Square();
  square.transform(translate(0, 0.45) * scale(5, 1));
  REQUIRE(intersects(square, circle));
}

TEST_CASE("Testing Intersection of Circle with Side of Square",
    "[intersects]") {
  auto circle = Circle();
  auto square = Square();
  square.transform(translate(0.45, 0) * scale(1, 5));
  REQUIRE(intersects(square, circle));
}

TEST_CASE("Testing Intersection of Circle Inscribed in Square",
    "[intersects]") {
  auto circle = Circle();
  auto square = Square();
  square.transform(scale(5));
  REQUIRE(intersects(square, circle));
}
