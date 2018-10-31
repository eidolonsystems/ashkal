#include "Ashkal/Shapes/Square.hpp"

using namespace Ashkal;

void Square::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Square Ashkal::make_rectangle(double width, double height) {
  auto s = Square();
  s.transform(scale(width, height));
  return s;
}
