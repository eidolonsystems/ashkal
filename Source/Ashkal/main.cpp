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
          m_camera({0, 0}, {500, 500}) {
      resize(1000, 1000);
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      Ashkal::render(*m_stage, m_camera, static_cast<QWidget*>(this));
    }

    void mouseMoveEvent(QMouseEvent* event) override {
      if(m_is_dragging) {
        auto pos = m_camera.get_pos();
        m_camera.set_pos({pos.x + ((m_last_pos.x() - event->pos().x()) *
            (m_camera.get_region().get_width() / width())),
          pos.y + ((m_last_pos.y() - event->pos().y()) *
            (m_camera.get_region().get_height() / height()))});
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

    void resizeEvent(QResizeEvent* event) override {
      auto pixel_rect = rectFromPixel(m_camera, event->oldSize().width(),
        event->oldSize().height());
      //qDebug() << "c_w: " << m_camera.get_region().get_width();
      //qDebug() << "c_h: " << m_camera.get_region().get_height();
      qDebug() << "pr_w: " << pixel_rect.get_width();
      //qDebug() << "pr_h: " << pixel_rect.get_height();
      //qDebug() << "width: " << width();
      //qDebug() << "height: " << height();
      //qDebug() << "w: " << width() * pixel_rect.get_width();
      //qDebug() << "h: " << static_cast<double>(height()) * pixel_rect.get_height();
      m_camera.set_region({std::round(width() * pixel_rect.get_width()),
        std::round(height() * pixel_rect.get_height())});
      //auto pos = m_camera.get_pos();
      //auto d = event->oldSize().width() - width();
      //m_camera.set_pos({pos.x - ((d * pixel_rect.get_width() / 2)),
      //  pos.y});
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

    Rectangle rectFromPixel(const Camera& camera, int width, int height) {
      qDebug() << "w: " << width;
      qDebug() << "h: " << height;
      qDebug() << "c_w: " << camera.get_region().get_width();
      qDebug() << "c_h: " << camera.get_region().get_height();

      auto c_w = camera.get_region().get_width();
      auto c_h = camera.get_region().get_height();
      auto w = width / c_w;
      if(std::isinf(w)) {
        w = 1;
      }
      auto h = height / c_h;
      if(std::isinf(h)) {
        h = 1;
      }
      qDebug() << "r: " << w << " " << h;
      return {w, h};
    }
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto stage = Stage();
  stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{50, 650});
  //stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{350, 650});
  //stage.add_shape(std::make_unique<Rectangle>(300, 300), Point{650, 650});
  //stage.add_shape(std::make_unique<Triangle>(Point{100, 900}, Point{100, 700},
  //  Point{200, 800}), Point{500, 500});
  //stage.add_shape(std::make_unique<Line>(Point{900, 900}), Point{100, 100});
  //stage.add_shape(std::make_unique<Ellipse>(450, 200), Point{500, 500});
  //stage.add_shape(std::make_unique<Rectangle>(200, 200), Point{1200, 500});
  auto w = new DrawManager(stage);
  w->show();
  application.exec();
}
