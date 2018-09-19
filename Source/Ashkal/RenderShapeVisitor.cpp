#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include <QPainter>
#include <Ashkal/Shapes/Ellipse.hpp>
#include <Ashkal/Shapes/Line.hpp>
#include <Ashkal/Shapes/Rectangle.hpp>
#include <Ashkal/Shapes/Triangle.hpp>

using namespace Ashkal;
using namespace std;

namespace {
  QPoint get_qt_coordinates(QWidget* widget, const Point& point) {
    return QPoint(static_cast<int>(point.x),
      widget->height() - static_cast<int>(point.y));
  }
}

void Ashkal::render(const Shape& shape, const Point& point, QWidget* widget) {
  struct Visitor final : ShapeVisitor {
    void operator ()(const Shape& shape, const Point& point, QWidget* widget) {
      m_point = point;
      m_widget = widget;
      shape.accept(*this);
    }

    void visit(const Ellipse& ellipse) override {
      auto pos = get_qt_coordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawEllipse(pos, static_cast<int>(ellipse.get_width()),
        static_cast<int>(ellipse.get_height()));
    }

    void visit(const Line& line) override {
      auto point = get_qt_coordinates(m_widget, line.get_point());
      auto pos = get_qt_coordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawLine(pos, point);
    }

    void visit(const Rectangle& rect) override {
      auto pos = get_qt_coordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawRect(pos.x(), pos.y(), static_cast<int>(rect.get_width()),
        static_cast<int>(rect.get_height()));
    }

    void visit(const Triangle& triangle) override {
      auto points = triangle.get_points();
      QPoint qt_points[3];
      qt_points[0] = get_qt_coordinates(m_widget, points[0]);
      qt_points[1] = get_qt_coordinates(m_widget, points[1]);
      qt_points[2] = get_qt_coordinates(m_widget, points[2]);
      auto painter = QPainter(m_widget);
      painter.drawPolygon(qt_points, 3);
    }

    Point m_point;
    QWidget* m_widget;
  };
  Visitor()(shape, point, widget);
}
