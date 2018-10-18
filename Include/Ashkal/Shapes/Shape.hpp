#ifndef ASHKAL_SHAPE_HPP
#define ASHKAL_SHAPE_HPP
#include "Ashkal/Ashkal/ShapeVisitor.hpp"
#include "Ashkal/Ashkal/Matrix.hpp"

namespace Ashkal {

  //! Represents an abstract shape.
  class Shape {
    public:

      Shape();

      virtual ~Shape() = default;

      virtual void accept(ShapeVisitor& visitor) const = 0;

      void transform(const Matrix& m);

      const Matrix& getTransformation() const;

    protected:
      Matrix m_transformation;
  };
}

#endif
