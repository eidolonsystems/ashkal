#ifndef ASHKAL_STAGE_HPP
#define ASHKAL_STAGE_HPP
#include "Ashkal/Shapes/Shapes.hpp"

class QWidget;

namespace Ashkal {

  class Stage {
    public:

      Stage() = default;

      //! Adds a shape to the stage.
      void add_shape(std::unique_ptr<Shape> shape);

      //! Returns the vector of shapes.
      const std::vector<std::unique_ptr<Shape>>&
        get_shapes() const;

    private:
      std::vector<std::unique_ptr<Shape>> m_shapes;

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
