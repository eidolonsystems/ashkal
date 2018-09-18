#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include <QPainter>
#include <Ashkal/Shapes/Circle.hpp>
#include <Ashkal/Shapes/Line.hpp>

using namespace Ashkal;

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

    void visit(const Circle& circle) override {
      auto pos = get_qt_coordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawEllipse(pos, static_cast<int>(2 * circle.get_radius()),
        static_cast<int>(2 * circle.get_radius()));
    }

    void visit(const Line& line) override {
      auto point = get_qt_coordinates(m_widget, line.get_point());
      auto pos = get_qt_coordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawLine(pos, point);
    }

    Point m_point;
    QWidget* m_widget;
  };
  Visitor()(shape, point, widget);
}
