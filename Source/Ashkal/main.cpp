#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Ashkal/Resources.hpp"
#include "Ashkal/Shapes/Circle.hpp"
#include "Ashkal/Shapes/Line.hpp"
#include "Ashkal/Shapes/Shape.hpp"
#include "Ashkal/Shapes/Stage.hpp"

using namespace Ashkal;

class Viewport : public QWidget {
  public:

    Viewport(const Stage& stage)
      : m_stage(&stage) {
      setFixedSize(SIZE, SIZE);
    }

  protected:
    void paintEvent(QPaintEvent* event) override {
      QWidget::paintEvent(event);
      for(auto& shape : m_stage->get_shapes()) {
        if(typeid(*shape.first.get()) == typeid(Line)) {
          auto s = static_cast<Line*>(shape.first.get());
          auto start = get_qt_coordinates(s->get_start_point());
          auto end = get_qt_coordinates(s->get_end_point());
          auto painter = new QPainter(this);
          painter->drawLine(start, end);
          painter->end();
        } else if(typeid(*shape.first.get()) == typeid(Circle)) {
          auto s = static_cast<Circle*>(shape.first.get());
          auto pos = get_qt_coordinates(shape.second);
          auto painter = new QPainter(this);
          painter->drawEllipse(pos, static_cast<int>(s->get_radius()) * 2,
            static_cast<int>(s->get_radius()) * 2);
          painter->end();
        }
      }
    }

  private:
    static constexpr auto SIZE = 1000;
    const Stage* m_stage;

    QPoint get_qt_coordinates(const Point& point) {
      return QPoint(static_cast<int>(point.x),
        SIZE - static_cast<int>(point.y));
    }
};

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  Stage stage;
  Point start;
  start.x = 200;
  start.y = 200;
  Point end;
  end.x = 400;
  end.y = 400;
  stage.add_shape(std::make_unique<Line>(start, end), start);
  Point pos;
  pos.x = 25;
  pos.y = 25;
  stage.add_shape(std::make_unique<Circle>(150), pos);
  auto window = new Viewport(stage);
  window->show();
  window->repaint();
  application.exec();
}
