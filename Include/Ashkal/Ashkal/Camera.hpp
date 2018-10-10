#ifndef ASHKAL_CAMERA_HPP
#define ASHKAL_CAMERA_HPP
#include "Ashkal/Ashkal/Point.hpp"
#include "Ashkal/Shapes/Rectangle.hpp"

namespace Ashkal {

  //! Defines a drawable region.
  class Camera {
    public:

      //! Constructs a Camera with a region and position of (0, 0);
      Camera();

      //! Constructs a Camera.
      /*
        \param region Defines the width and height of the drawable region.
        \param pos Defines the position of the drawable region.
      */
      Camera(const Rectangle& region, const Point& pos);

      const Rectangle& get_region() const;

      void set_region(const Rectangle& region);

      const Point& get_pos() const;

      void set_pos(const Point& pos);

    private:
      Rectangle m_region;
      Point m_pos;
  };
}

#endif
