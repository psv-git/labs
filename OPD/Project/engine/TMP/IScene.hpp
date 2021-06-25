#ifndef ISCENE_H
#define ISCENE_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class IScene {

    public:
      IScene();
      virtual ~IScene() = 0;

      virtual string getName() = 0;
      virtual Vector2f getSize() = 0;
      virtual Vector2i getTileSize() = 0;
      virtual Vector2i getTilesCount() = 0;
      virtual string getProperty(const string &name) = 0;

  };


}


#endif // ISCENE_H
