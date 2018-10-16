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
        \param row1 Initial values in row 1.
        \param row2 Initial values in row 2.
        \param row3 Initial values in row 3.
      */
      Matrix(std::initializer_list<double> row1,
        std::initializer_list<double> row2,
        std::initializer_list<double> row3);

      double& get(int row, int col);

      double get(int row, int col) const;

    private:
      double m_data[3][3];
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
