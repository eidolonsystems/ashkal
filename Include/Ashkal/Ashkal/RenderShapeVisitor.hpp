#ifndef ASHKAL_RENDER_SHAPE_VISITOR_HPP
#define ASHKAL_RENDER_SHAPE_VISITOR_HPP
#include <QWidget>
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  //! Renders a shape onto a widget.
  /*
    \param shape The Shape to be drawn.
    \param pos The position of the Shape.
    \param widget The widget the Shape is drawn onto.
  */
  void render(const Shape& shape, const Point& pos, QWidget* widget);
}

#endif