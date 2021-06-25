#ifndef APPLICATION_H
#define APPLICATION_H


#include "../engine/EngineCore.hpp"
#include "../engine/EventHandler.hpp"

#include "controllers/ObjectController.hpp"


class Application {

  public:
  
    Application();
    ~Application();

    void run();

  private:

    path getExecutableDir();
    path getResourcesDir();

};


#endif // APPLICATION_H
