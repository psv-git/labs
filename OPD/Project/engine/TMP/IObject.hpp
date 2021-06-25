#ifndef OBJECT_H
#define OBJECT_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "../base/AObject.hpp"
#include "../base/IEvents.hpp"


namespace engine {


  class Object : public AObject, public IEvents {

    public:
      Object();
      ~Object();

      void setSprite(sf::Sprite sprite);
      void setName(const std::string &name);
      void setType(const std::string &type);
      void setRect(sf::FloatRect objectRect);
      void setProperties(std::map<std::string, std::string> properties);

  };


}


#endif // OBJECT_H
