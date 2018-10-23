#ifndef ASHKAL_MATRIX_HPP
#define ASHKAL_MATRIX_HPP
#include <array>
#include <initializer_list>

namespace Ashkal {

  // Represents a 3x3 matrix.
  class Matrix {
    public:

      // Returns the identity matrix.
      static const Matrix& get_identity();

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

      // Returns the value at (row, col)
      /*
        \param row The row to get the value at.
        \param col The column to get the value at.
      */
      double& get(int row, int col);

      // Returns the value at (row, col)
      /*
        \param row The row to get the value at.
        \param col The column to get the value at.
      */
      double get(int row, int col) const;

    private:
      std::array<std::array<double, 3>, 3> m_data;
  };

  //! Returns a rotation matrix about the origin.
  /*
    \param r The angle of rotation, in radians.
  */
  Matrix rotate(double r);

  //! Returns a scaling matrix.
  /*
    \param s The scaling factor to apply both horizontally and vertically.
  */
  Matrix scale(double s);

  //! Returns a scaling matrix.
  /*
    \param x The horizontal scaling factor.
    \param y The vertical scaling factor.
  */
  Matrix scale(double x, double y);

  //! Returns a translation matrix.
  /*
    \param x The amount to move the x axis.
    \param y The amount to move the y axis.
  */
  Matrix translate(double x, double y);

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
