#ifndef ASHKAL_RENDER_SHAPE_VISITOR_HPP
#define ASHKAL_RENDER_SHAPE_VISITOR_HPP
#include <QWidget>
#include "Ashkal/Ashkal/Camera.hpp"
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Shape.hpp"
#include "Ashkal/Shapes/Stage.hpp"

namespace Ashkal {

  //! Renders a shape onto a widget.
  /*
    \param shape The Shape to be drawn.
    \param pos The position of the Shape.
    \param widget The widget the Shape is drawn onto.
  */
  void renderShape(const Shape& shape, const Point& pos, const Camera& camera,
    QWidget* widget);

  //! Renders the contents of a stage onto a widget.
  /*
    \param stage The stage to render.
    \param camera The camera used to 
  */
  void render(const Stage& stage, const Camera& camera, QWidget* widget);
}

#endif
