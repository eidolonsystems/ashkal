#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
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
  public:
    DrawWidget() {
      label = new QLabel(this);
      label->move(10, 50);
      label->setFixedWidth(100);
    }

    void increase_y() {
      m_pos2.y += 50;
      repaint();
    }

    void decrease_y() {
      m_pos2.y -= 50;
      update();
      repaint();
    }
    
    void increase_x() {
      m_pos2.x += 50;
      repaint();
    }

    void decrease_x() {
      m_pos2.x -= 50;
      update();
      repaint();
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      QWidget::paintEvent(event);
      auto pos = Point{300, 350};
      auto rect = make_square(100);
      Ashkal::render(rect, pos, this);
      auto rect2 = make_square(300);
      Ashkal::render(rect2, m_pos2, this);
      label->setText(QString("Intersects: %1")
        .arg(Ashkal::intersects(rect, pos, rect2, m_pos2)));
    }

  private:
    QLabel* label;
    Point m_pos2 = {200, 300};
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
  auto increase_y = new QPushButton("Increase Y", w);
  w->connect(increase_y, &QPushButton::clicked, [=] { w->increase_y(); });
  increase_y->move(0, 0);
  increase_y->show();
  auto decrease_y = new QPushButton("Decrease Y", w);
  w->connect(decrease_y, &QPushButton::clicked, [=] { w->decrease_y(); });
  decrease_y->move(100, 0);
  decrease_y->show();
  auto increase_x = new QPushButton("Increase X", w);
  w->connect(increase_x, &QPushButton::clicked, [=] { w->increase_x(); });
  increase_x->move(200, 0);
  increase_x->show();
  auto decrease_x = new QPushButton("Decrease X", w);
  w->connect(decrease_x, &QPushButton::clicked, [=] { w->decrease_x(); });
  decrease_x->move(300, 0);
  decrease_x->show();
  application.exec();
}
