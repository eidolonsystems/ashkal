#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Ashkal/ShapeVisitor.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

namespace {
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

  bool is_within_value(double pt1, double pt2, double value) {
    auto ordered_pts = std::minmax(pt1, pt2);
    return std::clamp(value, ordered_pts.first, ordered_pts.second) == value;
  }

  bool rect_contains(const std::array<std::pair<Point, Point>, 4> lines,
      const Point& pt) {
    return is_within_value(lines[0].first.x, lines[1].first.x, pt.x) &&
      is_within_value(lines[0].first.y, lines[3].first.y, pt.y);
  }
}

bool Ashkal::intersects(const Square& square, const Shape& shape) {
  struct Visitor final : ShapeVisitor {
    bool operator()(const Square& square, const Shape& shape) {
      m_intersects = false;
      m_square = &square;
      shape.accept(*this);
      return m_intersects;
    }

    void visit(const Circle& circle) override {
      auto lines = get_lines(*m_square, invert(circle.get_transformation()));
      for(auto& line : lines) {
        if(distance(line.first, Point{0, 0}) <= 1) {
          m_intersects = true;
          return;
        }
      }
      for(auto& line : lines) {
        auto s = slope(line.first, line.second);
        auto a = 1 + (s * s);
        auto y = y_intercept(line.first, s);
        auto b = 2 * y * s;
        auto c = -1 + (y * y);
        auto root1 = (-b + std::sqrt(std::pow(b, 2) - (4 * a * c))) / (2 * a);
        auto root2 = (-b - std::sqrt(std::pow(b, 2) - (4 * a * c))) / (2 * a);
        if(s == 0 && (is_within_value(line.first.x, line.second.x, root1) ||
            is_within_value(line.first.x, line.second.x, root2))) {
          m_intersects = true;
        } else if(std::isnan(s) &&
            (is_within_value(line.first.y, line.second.y, root1) ||
            is_within_value(line.first.y, line.second.y, root2))) {
          m_intersects = true;
        } else if((is_within_value(line.first.x, line.second.x, root1) &&
            is_within_value(line.first.y, line.second.y, root1)) ||
            is_within_value(line.first.x, line.second.x, root2) &&
            is_within_value(line.first.y, line.second.y, root2)) {
          m_intersects = true;
        } else if(rect_contains(lines, Point{0, 0})) {
          m_intersects = true;
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
    const Square* m_square;
  };
  return Visitor()(square, shape);
}
