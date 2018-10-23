#include "Ashkal/Shapes/Circle.hpp"

using namespace Ashkal;

void Circle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}

Circle Ashkal::make_ellipse(double width, double height) {
  auto e = Circle();
  e.transform(scale(width, height));
  return e;
}
