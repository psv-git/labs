#ifndef IEVENTS_H
#define IEVENTS_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class IEvents {

    public:
      IEvents() {}
      virtual ~IEvents() {}

      virtual void addEvent(const string &event) = 0;

  };


}


#endif // IEVENTS_H
