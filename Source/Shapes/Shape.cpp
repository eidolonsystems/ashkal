#include "Ashkal/Shapes/Shape.hpp"

using namespace Ashkal;

void Shape::transform(const Matrix& m) {
  m_transformation = m * m_transformation;
}

const Matrix& Shape::getTransformation() const {
  return m_transformation;
}

Shape::Shape()
    : m_transformation(Matrix::get_identity()) {}
