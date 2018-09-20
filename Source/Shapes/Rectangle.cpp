#include "Ashkal/Shapes/Rectangle.hpp"

using namespace Ashkal;

Rectangle::Rectangle()
  : Rectangle(0, 0) {}

Rectangle::Rectangle(double width, double height)
  : m_width(width),
    m_height(height) {}

double Rectangle::get_width() const {
  return m_width;
}

double Rectangle::get_height() const {
  return m_height;
}

void Rectangle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Rectangle Ashkal::make_square(double size) {
  return Rectangle(size, size);
}
