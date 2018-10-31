#include "Tests/TestUtility.hpp"

using namespace Ashkal;

bool Ashkal::equals(const Matrix& a, const Matrix& b, int sig_figures) {
  for(auto i = 0; i < 3; ++i) {
    for(auto j = 0; j < 3; ++j) {
      if(!equals(a.get(i, j), b.get(i, j), sig_figures)) {
        return false;
      }
    }
  }
  return true;
}

bool Ashkal::equals(double a, double b, int sig_figures) {
  if(std::abs(a - b) > std::pow(10, -(sig_figures - 1))) {
    return false;
  }
  return true;
}
