#include "Ashkal/Ashkal/Matrix.hpp"
#include <stdexcept>

using namespace Ashkal;

Matrix::Matrix()
  : Matrix({0, 0, 0}, {0, 0, 0}, {0, 0, 0}) {}

Matrix::Matrix(std::initializer_list<double> row1,
    std::initializer_list<double> row2, std::initializer_list<double> row3) {
  if(row1.size() != 3) {
    throw std::out_of_range("row1 size does not equal 3.");
  }
  std::copy(row1.begin(), row1.end(), m_data[0]);
  if(row2.size() != 3) {
    throw std::out_of_range("row2 size does not equal 3");
  }
  std::copy(row2.begin(), row2.end(), m_data[1]);
  if(row3.size() != 3) {
    throw std::out_of_range("row3 size does not equal 3.");
  }
  std::copy(row3.begin(), row3.end(), m_data[2]);
}

double& Matrix::get(int row, int col) {
  return m_data[row][col];
}

double Matrix::get(int row, int col) const {
  return m_data[row][col];
}

Matrix Ashkal::operator +(const Matrix& a, const Matrix& b) {
  return Matrix(
    {a.get(0, 0) + b.get(0, 0), a.get(0, 1) + b.get(0,1), a.get(0, 2) +
      b.get(0, 2)},
    {a.get(1, 0) + b.get(1, 0), a.get(1, 1) + b.get(1, 1), a.get(1, 2) +
      b.get(1, 2)},
    {a.get(2, 0) + b.get(2, 0), a.get(2, 1) + b.get(2, 1), a.get(2, 2) +
      b.get(2, 2)});
}

Matrix Ashkal::operator -(const Matrix& a, const Matrix& b) {
  return Matrix(
    {a.get(0, 0) - b.get(0, 0), a.get(0, 1) - b.get(0, 1), a.get(0, 2) -
      b.get(0, 2)},
    {a.get(1, 0) - b.get(1, 0), a.get(1, 1) - b.get(1, 1), a.get(1, 2) -
      b.get(1, 2)},
    {a.get(2, 0) - b.get(2, 0), a.get(2, 1) - b.get(2, 1), a.get(2, 2) -
    b.get(2, 2)});
}

Matrix Ashkal::operator *(const Matrix& a, const Matrix& b) {
  return Matrix();
}

Matrix Ashkal::operator *(double scalar, const Matrix& mat) {
  return Matrix(
    {scalar * mat.get(0, 0), scalar * mat.get(0, 1), scalar * mat.get(0, 2)},
    {scalar * mat.get(1, 0), scalar * mat.get(1, 1), scalar * mat.get(1, 2)},
    {scalar * mat.get(2, 0), scalar * mat.get(2, 1), scalar * mat.get(2, 2)});
}

bool Ashkal::operator ==(const Matrix& a, const Matrix& b) {
  for(auto i = 0; i < 3; ++i) {
    for(auto j = 0; j < 3; ++j) {
      if(a.get(i, j) != b.get(i, j)) {
        return false;
      }
    }
  }
  return true;
}

bool Ashkal::operator !=(const Matrix& a, const Matrix& b) {
  return !(a == b);
}

void Ashkal::invert(Matrix& mat) {
  auto determinant =
    (mat.get(0, 0) *
      (mat.get(1, 1) * mat.get(2, 2) - mat.get(2, 1) * mat.get(1, 2))) -
    (mat.get(1, 0) *
      (mat.get(0, 1) * mat.get(2, 2) - mat.get(2, 1) * mat.get(0, 2))) +
    (mat.get(2, 0) *
      (mat.get(0, 1) * mat.get(1, 2) - mat.get(1, 1) * mat.get(0, 2)));
  if(determinant == 0) {
    throw std::domain_error("Matrix is not invertible.");
  }
  auto minors = Matrix();
  minors.get(0, 0) = (mat.get(1, 1) * mat.get(2, 2)) -
    (mat.get(2, 1) * mat.get(1, 2));
  minors.get(0, 1) = (mat.get(0, 1) * mat.get(2, 2)) -
    (mat.get(2, 1) * mat.get(0, 2));
  minors.get(0, 2) = (mat.get(0, 1) * mat.get(1, 2)) -
    (mat.get(1, 1) * mat.get(0, 2));
  minors.get(1, 0) = (mat.get(1, 0) * mat.get(2, 2)) -
    (mat.get(2, 0) * mat.get(1, 2));
  minors.get(1, 1) = (mat.get(0, 0) * mat.get(2, 2)) -
    (mat.get(2, 0) * mat.get(0, 2));
  minors.get(1, 2) = (mat.get(0, 0) * mat.get(1, 2)) -
    (mat.get(1, 0) * mat.get(0, 2));
  minors.get(2, 0) = (mat.get(1, 0) * mat.get(2, 1)) -
    (mat.get(2, 0) * mat.get(1, 1));
  minors.get(2, 1) = (mat.get(0, 0) * mat.get(2, 1)) -
    (mat.get(2, 0) * mat.get(0, 1));
  minors.get(2, 2) = (mat.get(0, 0) * mat.get(1, 1)) -
    (mat.get(1, 0) * mat.get(0, 1));
  mat = (1 / determinant) * minors;
}

Matrix Ashkal::invert(const Matrix& mat) {
  auto inverse = mat;
  invert(inverse);
  return inverse;
}
