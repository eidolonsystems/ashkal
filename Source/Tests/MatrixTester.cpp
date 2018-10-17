#include <catch2/catch.hpp>
#include "Ashkal/Ashkal/Matrix.hpp"

using namespace Ashkal;

bool equals(const Matrix& a, const Matrix& b) {
  for(auto i = 0; i < 3; ++i) {
    for(auto j = 0; j < 3; ++j) {
      if(std::abs(a.get(i, j) - b.get(i, j)) > std::pow(10, -10)) {
        return false;
      }
    }
  }
  return true;
}

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

TEST_CASE("Testing multiplication of two matrices", "[operator*]") {
  auto mat1 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto mat2 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto result = Matrix(
    {30, 36, 42},
    {66, 81, 96},
    {102, 126, 150});
  REQUIRE(mat1 * mat2 == result);
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

TEST_CASE("Testing equality of matrices", "[operator==]") {
  auto mat1 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  auto mat2 = Matrix(
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9});
  REQUIRE(mat1 == mat2);
  auto mat3 = Matrix(
    {1, 2, 3},
    {44, 5, 6},
    {7, 8, 9});
  REQUIRE(!(mat1 == mat3));
}

TEST_CASE("Testing inverting of matrices", "[invert]") {
  auto mat1 = Matrix(
    {-1, -2, 2},
    {2, 1, 1},
    {3, 4, 5});
  auto result1 = Matrix(
    {1/23.0, 18/23.0, -4/23.0},
    {-7/23.0, -11/23.0, 5/23.0},
    {5/23.0, -2/23.0, 3/23.0});
  invert(mat1);
  REQUIRE(equals(mat1, result1));
  auto mat2 = Matrix(
    {10, 17, 12},
    {5, 10, 9},
    {21, 15, 13});
  auto result2 = Matrix(
    {-5/438.0, -41/438.0, 33/438.0},
    {124/438.0, -122/438.0, -30/438.0},
    {-135/438.0, 207/438.0, 15/438.0});
  invert(mat2);
  REQUIRE(equals(mat2, result2));
}
