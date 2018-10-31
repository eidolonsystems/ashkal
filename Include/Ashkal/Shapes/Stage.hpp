#ifndef ASHKAL_STAGE_HPP
#define ASHKAL_STAGE_HPP
#include "Ashkal/Shapes/Shapes.hpp"
#include "Ashkal/Ashkal/Point.hpp"

namespace Ashkal {

  class Stage {
    public:

      Stage() = default;

      //! Adds a shape at the specified Point.
      void add_shape(std::unique_ptr<Shape> shape, const Point& point);

      //! Returns the vector of shapes and their positions.
      const std::vector<std::pair<std::unique_ptr<Shape>, Point>>&
        getShapes() const;

    private:
      std::vector<std::pair<std::unique_ptr<Shape>, Point>> m_shapes;

      Stage(const Stage&) = delete;
      Stage& operator =(const Stage&) = delete;
  };

  void render(const Stage& stage, const Point& lens, const Square& region,
    QWidget* widget);
}

#endif
