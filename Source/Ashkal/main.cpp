#include <QApplication>
#include <QPaintEvent>
#include <QWidget>
#include "Ashkal/Ashkal/Resources.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Square.hpp"
#include "Ashkal/Shapes/Stage.hpp"

using namespace Ashkal;

class RenderedWidget : public QWidget {
  public:

    RenderedWidget(int width, int height, const Square& camera,
        Stage* stage)
        : m_camera(camera),
          m_stage(stage) {
      resize(width, height);
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      Ashkal::render(*m_stage, m_camera, this);
    }

  private:
    Square m_camera;
    Stage* m_stage;
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto camera = Square();
  camera.transform(translate(2, 0) * scale(5));
  auto stage = Stage();
  auto circle = std::make_unique<Circle>();
  circle->transform(rotate(0.78) * scale(0.4, 0.1));
  stage.add_shape(std::move(circle));
  auto w = new RenderedWidget(1000, 1000, camera, &stage);
  w->show();
  application.exec();
}
