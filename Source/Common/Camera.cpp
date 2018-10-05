#include "Ashkal/Ashkal/Camera.hpp"

using namespace Ashkal;

Camera::Camera()
  : Camera(Rectangle(0, 0), Point{0, 0}) {}

Camera::Camera(const Rectangle& region, const Point& pos)
    : m_region(region), m_pos(pos) {}

const Rectangle& Camera::get_region() const {
  return m_region;
}

void Camera::set_region(const Rectangle& region) {
  m_region = region;
}

const Point& Camera::get_pos() const {
  return m_pos;
}

void Camera::set_pos(const Point& pos) {
  m_pos = pos;
}
