#ifndef VECTORS_H
#define VECTORS_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class Vector2f : public sf::Vector2f {

    public:
      
      Vector2f() {}
      ~Vector2f() {}

      static const Vector2f zero;
      static const Vector2f up;
      static const Vector2f down;
      static const Vector2f left;
      static const Vector2f right;

  };
    
  const Vector2f Vector2f::zero = sf::Vector2f(0, 0);
  const Vector2f Vector2f::up = sf::Vector2f(0, 1.0);
  const Vector2f Vector2f::down = sf::Vector2f(0, -1.0);
  const Vector2f Vector2f::left = sf::Vector2f(-1.0, 0);
  const Vector2f Vector2f::right = sf::Vector2f(1.0, 0);
    

  class Vector2i : public sf::Vector2i {

    public:
      
      Vector2i() {}
      ~Vector2i() {}

      static const Vector2i zero;
      static const Vector2i up;
      static const Vector2i down;
      static const Vector2i left;
      static const Vector2i right;

  };
    
  const Vector2i zero = Vector2i(0, 0);
  const Vector2i up = Vector2i(0, 1);
  const Vector2i down = Vector2i(0, -1);
  const Vector2i left = Vector2i(-1, 0);
  const Vector2i right = Vector2i(1, 0);
    

  class Vector2u : public Vector2u {

    public:
      
      Vector2u() {}
      ~Vector2u() {}

      static const Vector2u zero;

  };
    
  static const Vector2u zero = Vector2u(0, 0);


}


#endif // VECTORS_H
