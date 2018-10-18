#include "Ashkal/Shapes/Shape.hpp"

using namespace Ashkal;

Shape::Shape()
    : m_transformation({1, 0, 0}, {0, 1, 0}, {0, 0, 1}) {}

void Shape::transform(const Matrix& m) {
  m_transformation = m_transformation * m;
}

const Matrix& Shape::get_transformation() const {
  return m_transformation;
}
