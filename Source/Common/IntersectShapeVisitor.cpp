#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Ashkal/ShapeVisitor.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

namespace {
  bool intersects_line(const Point& p1, const Point& p2) {
    return true;
  }

  std::array<std::pair<Point, Point>, 4> get_lines(const Square& square,
      const Matrix& transform) {
    auto lines = std::array<std::pair<Point, Point>, 4>();
    auto t = transform * square.get_transformation();
    lines[0] = {t * Point{-0.5, 0.5}, t * Point{0.5, 0.5}};
    lines[1] = {t * Point{0.5, 0.5}, t * Point{0.5, -0.5}};
    lines[2] = {t * Point{0.5, -0.5}, t * Point{-0.5, -0.5}};
    lines[3] = {t * Point{-0.5, -0.5}, t * Point{-0.5, 0.5}};
    return lines;
  }

  double y_intercept(const Point& p, double slope) {
    if(std::isnan(slope)) {
      return std::numeric_limits<double>::quiet_NaN();
    }
    return p.y - (p.x * slope);
  }

  bool is_within_line(double pt1, double pt2, double value) {
    auto high = std::max(pt1, pt2);
    auto low = std::min(pt1, pt2);
    return std::clamp(value, low, high) == value;
  }
}

bool Ashkal::intersects(const Square& square, const Shape& shape) {
  struct Visitor final : ShapeVisitor {
    bool operator()(const Square& square, const Shape& shape) {
      m_intersects = false;
      m_square = square;
      shape.accept(*this);
      return m_intersects;
    }

    void visit(const Circle& circle) override {
      auto lines = get_lines(m_square, invert(circle.get_transformation()));
      for(auto& l : lines) {
        auto s = slope(l.first, l.second);
        auto a = 1 + (2 * s);
        auto y = y_intercept(l.first, s);
        auto b = 2 * y * s;
        auto c = -1 + (y * y);
        auto root1 = (-b + std::sqrt(std::pow(b, 2) - (4 * a * c))) / (2 * a);
        auto root2 = (-b - std::sqrt(std::pow(b, 2) - (4 * a * c))) / (2 * a);
        if(s == 0) {
          if(is_within_line(l.first.x, l.second.x, root1) ||
              is_within_line(l.first.x, l.second.x, root2)) {
            m_intersects = true;
            return;
          }
        } else if(std::isnan(s)) {
          if(is_within_line(l.first.y, l.second.y, root1) ||
              is_within_line(l.first.y, l.second.y, root2)) {
            m_intersects = true;
            return;
          }
        } else {
          if((is_within_line(l.first.x, l.second.x, root1) &&
              is_within_line(l.first.y, l.second.y, root1)) ||
              is_within_line(l.first.x, l.second.x, root2) &&
              is_within_line(l.first.y, l.second.y, root2)) {
            m_intersects = true;
            return;
          }
        }
      }
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
