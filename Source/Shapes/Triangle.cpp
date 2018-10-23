#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

void Triangle::accept(ShapeVisitor& visitor) const {
  visitor.visit(*this);
}
