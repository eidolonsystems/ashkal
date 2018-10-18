#include "Ashkal/Shapes/Shape.hpp"

using namespace Ashkal;

Shape::Shape()
    : m_transformation(Matrix::get_identity()) {}

void Shape::transform(const Matrix& m) {
  m_transformation = m * m_transformation;
}

const Matrix& Shape::get_transformation() const {
  return m_transformation;
}
