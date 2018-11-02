#ifndef ASHKAL_STAGE_HPP
#define ASHKAL_STAGE_HPP
#include "Ashkal/Shapes/Shapes.hpp"
#include "Ashkal/Ashkal/Point.hpp"
class QWidget;

namespace Ashkal {

  class Stage {
    public:

      Stage() = default;

      //! Adds a shape at the specified Point.
      void add_shape(std::unique_ptr<Shape> shape, const Point& point);

      //! Returns the vector of shapes and their positions.
      const std::vector<std::pair<std::unique_ptr<Shape>, Point>>&
        get_shapes() const;

    private:
      std::vector<std::pair<std::unique_ptr<Shape>, Point>> m_shapes;

      Stage(const Stage&) = delete;
      Stage& operator =(const Stage&) = delete;
  };

  //! Renders a Stage onto a QWidget.
  /*
    \param stage The Stage to render.
    \param camera Determines which Shapes on the Stage to render.
    \param widget The widget to render the stage onto.
  */
  void render(const Stage& stage, const Square& camera,
    QWidget* widget);
}

#endif
