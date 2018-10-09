#include <QApplication>
#include <QKeyEvent>
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

    void keyReleaseEvent(QKeyEvent* event) override {
      if(event->key() == Qt::Key_Up) {
        m_camera.set_region(Rectangle(700, 700));
      } else if(event->key() == Qt::Key_Down) {
        m_camera.set_region(Rectangle(1000, 1000));
      } else if(event->key() == Qt::Key_Left) {
        m_camera.set_region(Rectangle(2000, 2000));
      }
      repaint();
    }

  private:
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
  auto w = new DrawManager(stage);
  w->show();
  application.exec();
}
