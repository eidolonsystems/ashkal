#include "Ashkal/Ashkal/Camera.hpp"

using namespace Ashkal;

Camera::Camera()
  : Camera(Matrix::get_identity()) {}

Camera::Camera(const Matrix& transform)
    : m_transformation(transform) {}

const Matrix& Camera::get_transformation() const {
  return m_transformation;
}
