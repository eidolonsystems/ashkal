#ifndef ASHKAL_TEST_UTILITY_HPP
#define ASHKAL_TEST_UTILITY_HPP
#include "Ashkal/Ashkal/Matrix.hpp"

namespace Ashkal {

  bool equals(const Matrix& a, const Matrix& b, int sig_figures = 14);

  bool equals(double a, double b, int sig_figures = 14);
}

#endif
