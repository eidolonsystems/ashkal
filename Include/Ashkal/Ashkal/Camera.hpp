#ifndef ASHKAL_CAMERA_HPP
#define ASHKAL_CAMERA_HPP
#include "Ashkal/Ashkal/Matrix.hpp"
#include "Ashkal/Shapes/Square.hpp"

namespace Ashkal {

  //! Defines a drawable region.
  class Camera {
    public:

      //! Constructs a Camera with size and position of (0, 0).
      Camera();

      //! Constructs a Camera with specified transformation.
      /*
        \param transform The Transformation to apply to the camera.
      */
      Camera(const Matrix& transform);

      const Matrix& get_transformation() const;

    private:
      Matrix m_transformation;
  };
}

#endif
