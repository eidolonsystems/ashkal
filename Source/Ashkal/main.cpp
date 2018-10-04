#include <QApplication>
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
        : m_stage(stage),
          m_camera(Rectangle(1000, 1000), Point{0, 0}) {
      setFixedSize(100, 100);
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      for(auto& [shape, pos] : m_stage.get_shapes()) {
        if(Ashkal::intersects(m_camera.get_region(), m_camera.get_pos(),
           *shape, pos)) {
          Ashkal::render(*shape, pos, this);
        }
      }
    }

  private:
    Camera m_camera;
    Stage m_stage;
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto stage = Stage();
  stage.add_shape(std::make_unique<Rectangle>(100, 100), Point{100, 100});
  stage.add_shape(std::make_unique<Triangle>(
    Point{-100, -100}, Point{-300, 0}, Point{100, -100}), Point{});
  auto w = new DrawManager(stage);
  w->show();
  application.exec();
}
