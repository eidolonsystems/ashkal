#include "Ashkal/Ashkal/Camera.hpp"

using namespace Ashkal;

Camera::Camera(const Rectangle& region, const Point& pos)
    : m_region(region), m_pos(pos) {}

const Rectangle& Camera::get_region() const {
  return m_region;
}

const Point& Camera::get_pos() const {
  return m_pos;
}
