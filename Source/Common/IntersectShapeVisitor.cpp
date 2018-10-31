#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Ashkal/ShapeVisitor.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

bool Ashkal::intersects(const Square& square, const Shape& shape) {
  struct Visitor final : ShapeVisitor {
    bool operator()(const Square& square, const Shape& shape) {
      m_intersects = false;
      m_square = square;
      shape.accept(*this);
      return m_intersects;
    }

    void visit(const Circle& circle) override {
    
    }

    void visit(const Line& line) override {
    
    }

    void visit(const Square& rect) override {
    
    }

    void visit(const Triangle& triangle) override {
    
    }

    bool m_intersects;
    Square m_square;
  };
  return Visitor()(square, shape);
}
