#include "Ashkal/Shapes/Stage.hpp"
#include "Ashkal/Shapes/Shape.hpp"

using namespace std;
using namespace Ashkal;

void Stage::addShape(unique_ptr<Shape> shape, const Point& point) {
  m_shapes.push_back(pair(std::move(shape), point));
}

const vector<pair<unique_ptr<Shape>, Point>>& Stage::getShapes() const {
  return m_shapes;
}

void Ashkal::render(const Stage& stage, const Point& lens,
    const Rectangle& region, QWidget* widget) {
  
}
