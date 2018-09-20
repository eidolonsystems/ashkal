#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

bool Ashkal::intersects(const Rectangle& a, const Point& p1, const Shape& b,
    const Point& p2) {
  struct Visitor final : ShapeVisitor {
    bool operator ()(const Rectangle& a, const Point& p1, const Shape& b,
        const Point& p2) {
      m_intersects = false;
      m_rect = a;
      m_rect_pos = p1;
      m_shape_pos = p2;
      b.accept(*this);
      return m_intersects;
    }

    void visit(const Ellipse& ellipse) override {
      
    }

    void visit(const Line& ellipse) override {
      
    }

    void visit(const Rectangle& rect) override {
      auto a_right = m_rect_pos.x + m_rect.get_width();
      auto a_bottom = m_rect_pos.y - m_rect.get_height();
      auto b_right = m_shape_pos.x + rect.get_width();
      auto b_bottom = m_shape_pos.y - rect.get_height();
      if(a_bottom > m_shape_pos.y || m_rect_pos.y < b_bottom ||
          a_right < m_shape_pos.x || m_rect_pos.x > b_right) {
        return;
      }
      m_intersects = true;
    }

    void visit(const Triangle& triangle) override {
      
    }

    bool m_intersects;
    Rectangle m_rect;
    Point m_rect_pos;
    Point m_shape_pos;
  };
  return Visitor()(a, p1, b, p2);
}
