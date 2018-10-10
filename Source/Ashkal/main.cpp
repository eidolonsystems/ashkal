#include <QApplication>
#include <QScrollEvent>
#include <QWidget>
#include "Ashkal/Ashkal/Camera.hpp"
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include "Ashkal/Ashkal/Resources.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Stage.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

class DrawManager : public QWidget {
  public:
    DrawManager(const Stage& stage)
        : m_stage(&stage),
          m_camera(Rectangle(1000, 1000), Point{500, 500}) {
      resize(1000, 1000);
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      Ashkal::render(*m_stage, m_camera, static_cast<QWidget*>(this));
    }

    void mouseMoveEvent(QMouseEvent* event) override {
      if(m_is_dragging) {
        auto pos = m_camera.get_pos();
        m_camera.set_pos({pos.x + (m_last_pos.x() - event->pos().x()),
          pos.y + (m_last_pos.y() - event->pos().y())});
        m_last_pos = event->pos();
        repaint();
      }
    }

    void mousePressEvent(QMouseEvent* event) override {
      if(event->button() == Qt::LeftButton) {
        m_is_dragging = true;
        m_last_pos = event->pos();
      }
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
      if(event->button() == Qt::LeftButton) {
        m_is_dragging = false;
      }
    }

    void wheelEvent(QWheelEvent* event) override {
      auto region = m_camera.get_region();
      if(event->angleDelta().y() > 0) {
        m_camera.set_region({region.get_width() - ZOOM_STEP,
          region.get_height() - ZOOM_STEP});
      } else if(event->angleDelta().y() < 0) {
        m_camera.set_region({region.get_width() + ZOOM_STEP,
          region.get_height() + ZOOM_STEP});
      }
      repaint();
    }

  private:
    const int ZOOM_STEP = 100;
    QPoint m_last_pos;
    bool m_is_dragging;
    Camera m_camera;
    const Stage* m_stage;
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto stage = Stage();
  stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{50, 650});
  stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{350, 650});
  stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{650, 650});
  stage.add_shape(std::make_unique<Triangle>(Point{100, 900}, Point{100, 700},
    Point{200, 800}), Point{500, 500});
  stage.add_shape(std::make_unique<Line>(Point{900, 900}), Point{100, 100});
  stage.add_shape(std::make_unique<Ellipse>(450, 200), Point{500, 500});
  auto w = new DrawManager(stage);
  w->show();
  application.exec();
}
