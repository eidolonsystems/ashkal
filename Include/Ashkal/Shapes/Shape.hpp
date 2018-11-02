#ifndef ASHKAL_SHAPE_HPP
#define ASHKAL_SHAPE_HPP
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Ashkal/ShapeVisitor.hpp"

namespace Ashkal {

  //! Represents an abstract shape.
  class Shape {
    public:

      virtual ~Shape() = default;

      virtual void accept(ShapeVisitor& visitor) const = 0;

      //! Applies a transformation to this Shape.
      /*
        \param m The transformation to apply.
      */
      void transform(const Matrix& m);

      //! Returns the transformation applied to this Shape.
      const Matrix& get_transformation() const;

    protected:
      //! Constructs a Shape with an identity matrix as the default
      //! transformation.
      Shape();

    private:
      Matrix m_transformation;
  };
}

#endif
