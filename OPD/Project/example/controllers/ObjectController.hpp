#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H


#include "../../engine/interfaces/IEvents.hpp"
#include "../../engine/controllers/AObjectController.hpp"


namespace engine {


  class ObjectController : public AObjectController, public IEvents {

    public:

      ObjectController(EventHandler *eventHandler);
      ~ObjectController();

      void addEvent(const string &event);

    private:

      void onKeyPressed();

  };


}


#endif // OBJECTCONTROLLER_H
