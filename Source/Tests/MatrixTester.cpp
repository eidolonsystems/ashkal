#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"

using namespace Ashkal;

TEST_CASE("Testing addition of Matrices", "[operator+]") {
  auto mat1 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto mat2 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto result = Matrix(
    {2, 4, 6},
    {8, 10, 12},
    {14, 16, 18});
  REQUIRE(mat1 + mat2 == result);
}

TEST_CASE("Testing subtraction of Matrices", "[operator-]") {
  auto mat1 = Matrix(
    {2, 4, 6},
    {8, 10, 12},
    {14, 16, 18});
  auto mat2 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto result1 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  REQUIRE(mat1 - mat2 == result1);
  auto mat3 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto mat4 = Matrix(
    {2, 4, 6},
    {8, 10, 12},
    {14, 16, 18});
  auto result2 = Matrix(
    {-1, -2, -3},
    {-4, -5, -6},
    {-7, -8, -9});
  REQUIRE(mat3 - mat4 == result2);
}

TEST_CASE("Testing multiplication of Matrix and scalar", "[operator*]") {
  auto scalar = 2;
  auto mat = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto result = Matrix(
    {2, 4, 6},
    {8, 10, 12},
    {14, 16, 18});
  REQUIRE(scalar * mat == result);
}
