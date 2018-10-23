#include "Tests/TestUtility.hpp"

using namespace Ashkal;

bool Ashkal::equals(const Matrix& a, const Matrix& b) {
  for(auto i = 0; i < 3; ++i) {
    for(auto j = 0; j < 3; ++j) {
      if(std::abs(a.get(i, j) - b.get(i, j)) > std::pow(10, -15)) {
        return false;
      }
    }
  }
  return true;
}
