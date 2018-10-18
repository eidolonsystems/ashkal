#ifndef ASHKAL_SHAPE_HPP
#define ASHKAL_SHAPE_HPP
#include "Ashkal/Ashkal/ShapeVisitor.hpp"
#include "Ashkal/Ashkal/Matrix.hpp"

namespace Ashkal {

  //! Represents an abstract shape.
  class Shape {
    public:

      // Constructs a Shape with an identity matrix as the default
      // transformation.
      Shape();

      virtual ~Shape() = default;

      virtual void accept(ShapeVisitor& visitor) const = 0;

      // Applies a transformation to this Shape.
      void transform(const Matrix& m);

      // Returns the transformation applied to this Shape.
      const Matrix& getTransformation() const;

    protected:
      Matrix m_transformation;
  };
}

#endif
