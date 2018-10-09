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
  double mapTo(double value, double a1, double a2, double b1, double b2) {
    return ((value - a1) * ((b2 - b1) / (a2 - a1))) + b1;
  }

  QPoint translateStageToView(const Point& point, const Camera& camera,
      int width, int height) {
    auto left = camera.get_pos().x - (camera.get_region().get_width() / 2);
    auto right = camera.get_pos().x + (camera.get_region().get_width() / 2);
    auto top = camera.get_pos().y - (camera.get_region().get_height() / 2);
    auto bottom = camera.get_pos().y + (camera.get_region().get_height() / 2);
    auto x = mapTo(point.x, left, right, 0, width - 1);
    auto y = mapTo(height - point.y, top, bottom, 0, height - 1);
    return QPoint(static_cast<int>(x), static_cast<int>(y));
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
      auto pos = translateStageToView(m_point, m_camera, m_widget->width(),
        m_widget->height());
      auto x_ratio = m_widget->width() / m_camera.get_region().get_width();
      pos.setX(pos.x() - static_cast<int>(ellipse.get_x_radius() * x_ratio));
      auto y_ratio = m_widget->height() / m_camera.get_region().get_height();
      pos.setY(pos.y() - static_cast<int>(ellipse.get_y_radius() * y_ratio));
      auto painter = QPainter(m_widget);
      painter.drawEllipse(pos.x(), pos.y(),
        static_cast<int>(ellipse.get_x_radius() * x_ratio) * 2,
        static_cast<int>(ellipse.get_y_radius() * y_ratio) * 2);
     }

    void visit(const Line& line) override {
      auto point = translateStageToView(line.get_point(), m_camera,
        m_widget->width(), m_widget->height());
      auto pos = translateStageToView(m_point, m_camera, m_widget->width(),
        m_widget->height());
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
        qt_points[i] = translateStageToView(points[i], m_camera,
          m_widget->width(), m_widget->height());
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
