#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H


#include "global/EngineHeaders.hpp"
#include "global/EngineConstants.hpp"
#include "interfaces/IEvents.hpp"


namespace engine {
  

  class EventHandler {

    public:

      EventHandler();
      ~EventHandler();

      void addListner(IEvents *listner, const string &event);
      void deleteListner(IEvents *listner);
      void update(RenderWindow &window);

    private:

      Event event;
      vector<string> eventsList;
      map<string, vector<IEvents*>> listnersList;

      // std::vector<IEvents*> listeners;

      void addEvent(const string &event);

  };


}


#endif // EVENTHANDLER_H
