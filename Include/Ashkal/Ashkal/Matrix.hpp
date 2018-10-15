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
        \param row1 Values for row 1 of the Matrix.
        \param row2 Values for row 2 of the Matrix.
        \param row3 Values for row 3 of the Matrix.
      */
      Matrix(std::initializer_list<double> row1,
        std::initializer_list<double> row2,
        std::initializer_list<double> row3);

      const std::array<std::array<double, 3>, 3>& get_data() const;

    private:
      std::array<std::array<double, 3>, 3> m_data;
  };

  Matrix operator +(const Matrix& a, const Matrix& b);

  Matrix operator -(const Matrix& a, const Matrix& b);

  Matrix operator *(const Matrix& a, const Matrix& b);

  Matrix operator *(const Matrix& mat, double scalar);

  bool operator ==(const Matrix& a, const Matrix& b);

  bool operator !=(const Matrix& a, const Matrix& b);

  void invert(Matrix& mat);

  Matrix invert(const Matrix& mat);
}

#endif
