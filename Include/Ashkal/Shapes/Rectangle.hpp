#ifndef ASHKAL_RECTANGLE_HPP
#define ASHKAL_RECTANGLE_HPP
#include "Ashkal/Shapes/Shape.hpp"

namespace Ashkal {

  class Rectangle : public Shape {
    public:

      //! Constructs a Rectangle with width and height 0.
      Rectangle();

      //! Constructs a Rectangle with a defined width and height.
      /*
        \param width The width of the Rectangle.
        \param height The height of the Rectangle.
      */
      Rectangle(double width, double height);

      double get_width() const;

      double get_height() const;

      void accept(ShapeVisitor& visitor) const override;

    private:
      double m_width;
      double m_height;
  };

  //! Creates a square.
  /*
    \param size The width and height of the square.
  */
  Rectangle make_square(double size);
}

#endif
