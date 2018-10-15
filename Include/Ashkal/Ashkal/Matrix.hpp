#ifndef ASHKAL_MATRIX_HPP
#define ASHKAL_MATRIX_HPP
#include <array>
#include <initializer_list>

namespace Ashkal {

  // Represents a 3x3 matrix.
  class Matrix {
    public:

      // Constructs a zero matrix.
      Matrix();

      // Constructs a Matrix with initial values.
      /*
        \param values The initial values of the matrix.
      */
      Matrix(const std::array<std::array<double, 3>, 3>& values);

      double& get(int row, int col);

      double get(int row, int col) const;

    private:
      std::array<std::array<double, 3>, 3> m_data;
  };

  Matrix operator +(const Matrix& a, const Matrix& b);

  Matrix operator -(const Matrix& a, const Matrix& b);

  Matrix operator *(const Matrix& a, const Matrix& b);

  Matrix operator *(double scalar, const Matrix& mat);

  bool operator ==(const Matrix& a, const Matrix& b);

  bool operator !=(const Matrix& a, const Matrix& b);

  void invert(Matrix& mat);

  Matrix invert(const Matrix& mat);
}

#endif
