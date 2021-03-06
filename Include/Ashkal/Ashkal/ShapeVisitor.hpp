#ifndef ASHKAL_SHAPE_VISITOR_HPP
#define ASHKAL_SHAPE_VISITOR_HPP
#include "Ashkal/Shapes/Shapes.hpp"

namespace Ashkal {

  //! 
  class ShapeVisitor {
    public:

      virtual ~ShapeVisitor() = default;

      virtual void visit(const Circle& c) = 0;
      virtual void visit(const Line& l) = 0;
      virtual void visit(const Square& r) = 0;
      virtual void visit(const Triangle& t) = 0;
  };
}

#endif
