#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include <QPainter>
#include "Ashkal/Ashkal/Camera.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;
using namespace std;

namespace {
  QPoint getQtCoordinates(QWidget* widget, const Point& point) {
    return QPoint(static_cast<int>(point.x),
      widget->height() - static_cast<int>(point.y));
  }

  QPoint translateStageToView(const Point& point, const Camera& camera,
      int width, int height) {
    auto h = height / camera.get_region().get_height();
    auto w = width / camera.get_region().get_width();
    return QPoint(static_cast<int>(point.x * w),
      height - static_cast<int>(point.y * h));
  }
}

void Ashkal::renderShape(const Shape& shape, const Point& point,
    const Camera& camera, QWidget* widget) {
  struct Visitor final : ShapeVisitor {
    void operator ()(const Shape& shape, const Point& point,
        const Camera& camera, QWidget* widget) {
      m_point = point;
      m_widget = widget;
      m_camera = camera;
      shape.accept(*this);
    }

    void visit(const Ellipse& ellipse) override {
      auto rendered_pos = Point{m_point.x - ellipse.get_x_radius(),
        m_point.y + ellipse.get_y_radius()};
      auto pos = getQtCoordinates(m_widget, rendered_pos);
      auto painter = QPainter(m_widget);
      painter.drawEllipse(pos.x(), pos.y(),
        static_cast<int>(ellipse.get_x_radius() * 2),
        static_cast<int>(ellipse.get_y_radius() * 2));
     }

    void visit(const Line& line) override {
      auto point = getQtCoordinates(m_widget, line.get_point());
      auto pos = getQtCoordinates(m_widget, m_point);
      auto painter = QPainter(m_widget);
      painter.drawLine(pos, point);
    }

    void visit(const Rectangle& rect) override {
      auto top_left = translateStageToView(m_point, m_camera,
        m_widget->width(), m_widget->height());
      auto bottom_right = translateStageToView(
        {m_point.x + rect.get_width(), m_point.y - rect.get_height()},
        m_camera, m_widget->width(), m_widget->height());
      auto painter = QPainter(m_widget);
      painter.drawRect(QRect(top_left, bottom_right));
    }

    void visit(const Triangle& triangle) override {
      auto& points = triangle.get_points();
      auto qt_points = std::array<QPoint, 3>();
      for(auto i = 0; i < 3; ++i) {
        qt_points[i] = getQtCoordinates(m_widget, points[i]);
      }
      auto painter = QPainter(m_widget);
      painter.drawPolygon(qt_points.data(), 3);
    }

    Point m_point;
    Camera m_camera;
    QWidget* m_widget;
  };
  Visitor()(shape, point, camera, widget);
}

void Ashkal::render(const Stage& stage, const Camera& camera,
    QWidget* widget) {
  for(auto& [shape, pos] : stage.get_shapes()) {
    renderShape(*shape, pos, camera, widget);
  }
}
