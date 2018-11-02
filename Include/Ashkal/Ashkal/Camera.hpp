#ifndef ASHKAL_CAMERA_HPP
#define ASHKAL_CAMERA_HPP
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Shapes/Square.hpp"

namespace Ashkal {

  //! Defines a drawable region.
  class Camera {
    public:

      //! Constructs a Camera with size of 1x1 and position of (0, 0).
      Camera();

      //! Constructs a Camera with specified transformation.
      /*
        \param transform The transformation to apply to the camera.
      */
      Camera(const Matrix& transform);

      //! Returns the transformation applied to this Camera.
      const Matrix& get_transformation() const;

      //! Applies a transformation to this Camera.
      /*
        \param m The transformation to apply.
      */
      void transform(const Matrix& m);

    private:
      Matrix m_transformation;
  };
}

#endif
