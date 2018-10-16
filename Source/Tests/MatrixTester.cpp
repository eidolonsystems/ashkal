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
