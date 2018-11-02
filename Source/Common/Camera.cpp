#include "Ashkal/Ashkal/Camera.hpp"

using namespace Ashkal;

Camera::Camera()
    : Camera(scale(1)) {}

Camera::Camera(const Matrix& transform)
    : m_transformation(transform) {}

const Matrix& Camera::get_transformation() const {
  return m_transformation;
}

void Camera::transform(const Matrix& m) {
  m_transformation = m * m_transformation;
}
