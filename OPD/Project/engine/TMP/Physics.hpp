#ifndef PHYSICS_H
#define PHYSICS_H

#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class Physics {

    public:

      Physics();
      ~Physics();

      

    private:
    
      vector<Object*> objectsList;

  };


}


#endif // PHYSICS_H
