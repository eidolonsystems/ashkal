#include "Ashkal/Ashkal/Matrix.hpp"
#include <stdexcept>

using namespace Ashkal;

Matrix::Matrix()
  : Matrix({0, 0, 0}, {0, 0, 0}, {0, 0, 0}) {}

Matrix::Matrix(std::initializer_list<double> row1,
    std::initializer_list<double> row2,
    std::initializer_list<double> row3) {
  std::copy(row1.begin(), row1.end(), m_data[0]);
  std::copy(row2.begin(), row2.end(), m_data[1]);
  std::copy(row3.begin(), row3.end(), m_data[2]);
}

const std::array<std::array<double, 3>, 3>& Matrix::get_data() const {
  return m_data;
}

Matrix Ashkal::operator +(const Matrix& a, const Matrix& b) {
  auto& ad = a.get_data();
  auto& bd = b.get_data();
  return Matrix(
    {ad[0][0] + bd[0][0], ad[0][1] + bd[0][1], ad[0][2] + bd[0][2]},
    {ad[1][0] + bd[1][0], ad[1][1] + bd[1][1], ad[1][2] + bd[1][2]},
    {ad[2][0] + bd[2][0], ad[2][1] + bd[2][1], ad[2][2] + bd[2][2]});
}

Matrix Ashkal::operator -(const Matrix& a, const Matrix& b) {
  auto& ad = a.get_data();
  auto& bd = b.get_data();
  return Matrix(
    {ad[0][0] - bd[0][0], ad[0][1] - bd[0][1], ad[0][2] - bd[0][2]},
    {ad[1][0] - bd[1][0], ad[1][1] - bd[1][1], ad[1][2] - bd[1][2]},
    {ad[2][0] - bd[2][0], ad[2][1] - bd[2][1], ad[2][2] - bd[2][2]});
}

Matrix Ashkal::operator *(const Matrix& a, const Matrix& b) {

}

Matrix Ashkal::operator *(const Matrix& mat, double scalar) {
  auto& data = mat.get_data();
  return Matrix(
    {scalar * data[0][0], scalar * data[0][1], scalar * data[0][2]},
    {scalar * data[1][0], scalar * data[1][1], scalar * data[1][2]},
    {scalar * data[2][0], scalar * data[2][1], scalar * data[2][2]});
}

bool Ashkal::operator ==(const Matrix& a, const Matrix& b) {
  auto& ad = a.get_data();
  auto& bd = b.get_data();
  for(auto i = 0; i < 3; ++i) {
    for(auto j = 0; j < 3; ++j) {
      if(ad[i][j] != bd[i][j]) {
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
  auto& data = mat.get_data();
  auto determinant =
    ((data[0][0] * data[1][1] * data[2][2]) +
    (data[1][0] * data[2][1] * data[0][2]) +
    (data[2][0] * data[0][1] * data[1][2])) -
    ((data[1][0] * data[0][1] * data[2][2]) -
    (data[0][0] * data[2][1] * data[1][2]) -
    (data[2][0] * data[1][1] * data[0][2]));
  if(determinant == 0) {
    throw std::domain_error("Matrix is not invertible.");
  }

}

Matrix Ashkal::invert(const Matrix& mat) {
  auto inverse = mat;
  invert(inverse);
  return inverse;
}
