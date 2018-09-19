#include <QApplication>
#include <QWidget>
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Ashkal/RenderShapeVisitor.hpp"
#include "Ashkal/Ashkal/Resources.hpp"
#include "Ashkal/Shapes/Ellipse.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"
#include "Ashkal/Shapes/Stage.hpp"
#include "Ashkal/Shapes/Triangle.hpp"

using namespace Ashkal;

class DrawWidget : public QWidget {
  protected:
    void paintEvent(QPaintEvent* event) override {
      QWidget::paintEvent(event);
      auto pos = Point{150, 150};
      auto rect = Rectangle(200, 200);
      Ashkal::render(rect, pos, this);
      auto circ = Ellipse(100, 100);
      Ashkal::render(circ, pos, this);
    }
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  auto w = new DrawWidget();
  w->resize(1000, 1000);
  w->show();
  application.exec();
}
