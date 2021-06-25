#ifndef AOBJECTCONTROLLER_H
#define AOBJECTCONTROLLER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "../EventHandler.hpp"
#include "../containers/Object.hpp"


namespace engine {


  class AObjectController {

    public:

      AObjectController();
      virtual ~AObjectController() = 0;

      void setObject(Object *object);
      void setEventHandler(EventHandler *eventHandler);

    protected:

      Object *object;
      Transform transform;
      EventHandler *eventHandler;

      void move(float x, float y);
      void rotate(float angle);

  };


}


#endif // AOBJECTCONTROLLER_H
