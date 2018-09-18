#include <QApplication>
#include <QWidget>
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include "Ashkal/Ashkal/Resources.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Stage.hpp"

using namespace Ashkal;

class DrawWidget : public QWidget {
  protected:
    void paintEvent(QPaintEvent* event) override {
      QWidget::paintEvent(event);
      auto pos = Point{100, 100};
      auto circle = Circle(200);
      Ashkal::render(circle, pos, this);
      auto line = Line({200, 200});
      Ashkal::render(line, pos, this);
    }
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto w = new DrawWidget();
  w->setFixedSize(1000, 1000);
  w->show();
  application.exec();
}
