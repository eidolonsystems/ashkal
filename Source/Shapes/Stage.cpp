#include "Ashkal/Shapes/Stage.hpp"
#include <QPainter>
#include <QWidget>
#include "Ashkal/Ashkal/IntersectShapeVisitor.hpp"
#include "Ashkal/Shapes/Shape.hpp"
#include "Ashkal/Shapes/Square.hpp"

using namespace std;
using namespace Ashkal;

namespace {
  double mapTo(double value, double a1, double a2, double b1, double b2) {
    return ((value - a1) * ((b2 - b1) / (a2 - a1))) + b1;
  }

  Square pixelToSquare(const Square& camera, int width, int height, int x,
      int y) {
    auto pixel = Square();
    pixel.transform(
      scale(camera.get_transformation().get(0, 0) / width,
      camera.get_transformation().get(1, 1) / height));
    auto px = mapTo(x, 0, width - 1, -0.5, 0.5);
    auto py = mapTo(y, 0, height - 1,  0.5, -0.5);
    pixel.transform(translate(px, py));
    return pixel;
  }
}

void Stage::add_shape(unique_ptr<Shape> shape, const Point& point) {
  m_shapes.push_back(pair(std::move(shape), point));
}

const vector<pair<unique_ptr<Shape>, Point>>& Stage::get_shapes() const {
  return m_shapes;
}

void Ashkal::render(const Stage& stage, const Square& camera,
    QWidget* widget) {
  auto painter = QPainter(widget);

  for(auto i = 0; i < widget->width(); ++i) {
    for(auto j = 0; j < widget->height(); ++j) {
      for(auto& shape : stage.get_shapes()) {
        auto pixel = pixelToSquare(camera, widget->width(), widget->height(),
          i, j);
        if(intersects(pixel, *shape.first)) {
          painter.setPen(Qt::white);
        } else {
          painter.setPen(Qt::black);
        }
        painter.drawPoint(i, j);
      }
    }
  }
}
