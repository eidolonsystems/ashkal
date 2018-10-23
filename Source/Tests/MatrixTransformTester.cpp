#include <catch2/catch.hpp>
#include <cmath>
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Tests/TestUtility.hpp"

using namespace Ashkal;

TEST_CASE("Testing Matrix Translation", "[translate]") {
  auto result1 = Matrix(
    {1, 0, 5},
    {0, 1, 3},
    {0, 0, 1});
  REQUIRE(translate(5, 3) == result1);
  auto result2 = Matrix(
    {1, 0, -2},
    {0, 1, 4},
    {0, 0, 1});
  REQUIRE(translate(-2, 4) == result2);
}

TEST_CASE("Testing Matrix Scaling Uniformly", "[scale]") {
  auto result1 = Matrix(
    {3, 0, 0},
    {0, 3, 0},
    {0, 0, 1});
  REQUIRE(scale(3) == result1);
  auto result2 = Matrix(
    {-2, 0, 0},
    {0, -2, 0},
    {0, 0, 1});
  REQUIRE(scale(-2) == result2);
}

TEST_CASE("Testing Matrix Scaling With Independent X and Y values",
    "[scale]") {
  auto result1 = Matrix(
    {2, 0, 0},
    {0, 4, 0},
    {0, 0, 1});
  REQUIRE(scale(2, 4) == result1);
  auto result2 = Matrix(
    {-2, 0, 0},
    {0, -4, 0},
    {0, 0, 1});
  REQUIRE(scale(-2, -4) == result2);
}

TEST_CASE("Testing Matrix Rotation", "[rotate]") {
  auto r = 90 * ((std::atan(1) * 4) / 180);
  auto result1 = Matrix(
    {0, 1, 0},
    {-1, 0, 0},
    {0, 0, 1});
  REQUIRE(equals(rotate(r), result1));
  auto result2 = Matrix(
    {0, -1, 0},
    {1, 0, 0},
    {0, 0, 1});
  REQUIRE(equals(rotate(-r), result2));
}
