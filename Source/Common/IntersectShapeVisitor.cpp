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

    void visit(const Line& line) override {
      auto pos_x = line.get_point().x + m_shape_pos.x;
      auto pos_y = line.get_point().y + m_shape_pos.y;
      if(rect_contains(m_shape_pos) || rect_contains(Point{pos_x, pos_y})) {
        m_intersects = true;
      }
      for(auto rect_line : get_rect_lines()) {
        if(intersects(rect_line.first, rect_line.second, line, m_shape_pos)) {
          m_intersects = true;
        }
      }
    }

    void visit(const Rectangle& rect) override {
      auto m_rect_right = m_rect_pos.x + m_rect.get_width();
      auto m_rect_bottom = m_rect_pos.y - m_rect.get_height();
      auto shape_right = m_shape_pos.x + rect.get_width();
      auto shape_bottom = m_shape_pos.y - rect.get_height();
      if(m_rect_bottom > m_shape_pos.y || m_rect_pos.y < shape_bottom ||
          m_rect_right < m_shape_pos.x || m_rect_pos.x > shape_right) {
        return;
      }
      m_intersects = true;
    }

    void visit(const Triangle& triangle) override {
      
    }

    bool intersects(const Line& line1, const Point& line1_pos,
        const Line& line2, const Point& line2_pos) {
      auto slope1 = slope(line1.get_point(), line1_pos);
      auto slope2 = slope(line2.get_point(), line2_pos);
      auto y_intercept1 = y_intercept(line1_pos, slope1);
      auto y_intercept2 = y_intercept(line2_pos, slope2);
      auto x = solve_x(slope1, y_intercept1, slope2, y_intercept1);
      if(rect_contains(Point{x, m_rect_pos.y})) {
        return true;
      }
      return false;
    }

    std::array<std::pair<Line, Point>, 4> get_rect_lines() {
      auto lines = std::array<std::pair<Line, Point>, 4>();
      lines[0] = std::pair<Line, Point>(Line({m_rect.get_width(), 0}),
        m_rect_pos);
      lines[1] = std::pair<Line, Point>(Line({0, -m_rect.get_height()}),
            Point{m_rect_pos.x + m_rect.get_width(), m_rect_pos.y});
      lines[2] = std::pair<Line, Point>(Line({0, m_rect.get_width()}),
            Point{m_rect_pos.x, m_rect_pos.y - m_rect.get_height()});
      lines[3] = std::pair<Line, Point>(Line({0, -m_rect.get_height()}),
        m_rect_pos);
      return lines;
    }

    bool rect_contains(const Point& point) {
      return point.x >= m_rect_pos.x && point.x <=
        m_rect_pos.x + m_rect.get_width() && point.y <= m_rect_pos.y &&
        point.y >= m_rect_pos.y - m_rect.get_height();
    }

    double solve_y(double slope, double x, double y_intercept) {
      return (slope * x) / y_intercept;
    }

    double solve_x(double slope1, double y_intercept1, double slope2,
        double y_intercept2) {
      auto y_intercept = y_intercept1 - y_intercept2;
      auto slope = slope1 - slope2;
      return y_intercept / slope;
    }

    double y_intercept(const Point& point, double slope) {
      return point.y - (point.x * slope);
    }

    double slope(const Point& p1, const Point& p2) {
      auto denominator = p2.x - p1.x;
      if(denominator == 0) {
        return std::numeric_limits<double>::quiet_NaN();
      }
      return (p2.y - p1.y) / denominator;
    }

    bool m_intersects;
    Rectangle m_rect;
    Point m_rect_pos;
    Point m_shape_pos;
  };
  return Visitor()(a, p1, b, p2);
}
