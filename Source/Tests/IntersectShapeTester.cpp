#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Square.hpp"

using namespace Ashkal;

TEST_CASE("Testing Intersection of Inscribed Square and Circle",
    "[intersects]") {
  auto circle = Circle();
  auto square = Square();
  circle.transform(translate(-6, 10) * scale(2) *
    rotate(0.78539816339744830961566084581988));
  square.transform(translate(-6, 10));
  REQUIRE(intersects(square, circle));
}
