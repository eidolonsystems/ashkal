#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

namespace {
  double solve_y(double vertical_line_pos, double slope,
      double y_intercept) {
    return (slope * vertical_line_pos) + y_intercept;
  }

  double solve_x(double slope1, double y_intercept1, double slope2,
      double y_intercept2) {
    auto y_intercept = y_intercept1 - y_intercept2;
    auto slope = slope1 - slope2;
    return y_intercept / slope;
  }

  double y_intercept(const Point& point, double slope) {
    if(std::isnan(slope)) {
      return std::numeric_limits<double>::quiet_NaN();
    }
    return point.y - (point.x * slope);
  }

  double slope(const Point& p1, const Point& p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
  }

  bool rect_contains_x(const Rectangle& rect, const Point& rect_pos,
      double x) {
    return x >= rect_pos.x && x <= rect_pos.x + rect.get_width();
  }

  bool rect_contains_y(const Rectangle& rect, const Point& rect_pos,
      double y) {
    return y >= rect_pos.y - rect.get_height() && y <= rect_pos.y;
  }

  bool rect_contains(const Rectangle& rect, const Point& rect_pos,
      const Point& point) {
    //return point.x >= rect_pos.x && point.x <=
    //  rect_pos.x + rect.get_width() && point.y <= rect_pos.y &&
    //  point.y >= rect_pos.y - rect.get_height();
    return rect_contains_x(rect, rect_pos, point.x) &&
      rect_contains_y(rect, rect_pos, point.y);
  }
}

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
      if(rect_contains(m_rect, m_rect_pos, m_shape_pos) ||
          rect_contains(m_rect, m_rect_pos, Point{pos_x, pos_y})) {
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
      auto& points = triangle.get_points();
      auto lines = std::array<std::pair<Line, Point>, 3>();
      lines[0] = {Line({points[0]}), Point{points[1]}};
      lines[1] = {Line({points[1]}), Point{points[2]}};
      lines[2] = {Line({points[0]}), Point{points[2]}};
      for(auto& l : lines) {
        auto& line = l.first;
        auto& point = l.second;
        if(slope(line.get_point(), point) > 0) {
          if(line.get_point().x > point.x) {
            line = Line({line.get_point().x - point.x,
              line.get_point().y - point.y});
          } else {
            line = Line({line.get_point().x - point.x,
              line.get_point().y - point.y});
          }
        } else if(slope(line.get_point(), point) < 0) {
          if(line.get_point().x > point.x) {
            line = Line({line.get_point().x - point.x,
              point.y - line.get_point().y});
          } else {
            line = Line({line.get_point().x - point.x,
              line.get_point().y - point.y});
          }
        } else {
          if(line.get_point().x > point.x) {
            line = Line({line.get_point().x - point.x, 0});
          } else {
            line = Line({line.get_point().x - point.x, 0});
          }
        }
      }
      for(auto& tri_line : lines) {
        for(auto rect_line : get_rect_lines()) {
          if(intersects(rect_line.first, rect_line.second, tri_line.first,
              tri_line.second)) {
            m_intersects = true;
            return;
          }
        }
      }
    }

    bool intersects(const Line& line1, const Point& line1_pos,
        const Line& line2, const Point& line2_pos) {
      double slope1;
      double slope2;
      if(line1.get_point().x == 0 && line2.get_point().x == 0) {
        if(line1_pos.x == line2_pos.x) {
          return true;
        }
        return false;
      }
      if(line1.get_point().y != 0) {
        slope1 = slope(line1.get_point(), line1_pos);
      } else {
        slope1 = std::numeric_limits<double>::quiet_NaN();
      }
      if(line2.get_point().y != 0) {
        slope2 = slope(line2.get_point(), line2_pos);
      } else {
        slope2 = std::numeric_limits<double>::quiet_NaN();
      }
      if(std::isnan(slope1) && std::isnan(slope2)) {
        if(line1_pos.x == line2_pos.x && rect_contains_x(m_rect, m_rect_pos,
            line1_pos.x)) {
          return true;
        }
        return false;
      }
      auto y_intercept1 = y_intercept(line1_pos, slope1);
      auto y_intercept2 = y_intercept(line2_pos, slope2);
      double x;
      if(std::isnan(slope1)) {
        return rect_contains(m_rect, m_rect_pos,
          Point{line1_pos.x, solve_y(line1_pos.x, slope2, y_intercept2)});
      } else if(std::isnan(slope2)) {
        return rect_contains(m_rect, m_rect_pos,
          Point{line2_pos.x, solve_y(line2_pos.x, slope1, y_intercept1)});
      } else {
        x = solve_x(slope1, y_intercept1, slope2, y_intercept1);
      }
      return rect_contains_x(m_rect, m_rect_pos, x);
    }

    std::array<std::pair<Line, Point>, 4> get_rect_lines() {
      auto lines = std::array<std::pair<Line, Point>, 4>();
      lines[0] = std::pair<Line, Point>(Line({m_rect.get_width(), 0}),
        m_rect_pos);
      lines[1] = std::pair<Line, Point>(Line({0, -m_rect.get_height()}),
            Point{m_rect_pos.x + m_rect.get_width(), m_rect_pos.y});
      lines[2] = std::pair<Line, Point>(Line({m_rect.get_width(), 0}),
            Point{m_rect_pos.x, m_rect_pos.y - m_rect.get_height()});
      lines[3] = std::pair<Line, Point>(Line({0, -m_rect.get_height()}),
        m_rect_pos);
      return lines;
    }

    bool m_intersects;
    Rectangle m_rect;
    Point m_rect_pos;
    Point m_shape_pos;
  };
  return Visitor()(a, p1, b, p2);
}
