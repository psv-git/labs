#ifndef ENGINECORE_H
#define ENGINECORE_H


#include "global/EngineHeaders.hpp"
#include "global/EngineConstants.hpp"
#include "managers/SceneManager.hpp"
#include "managers/WindowManager.hpp"
#include "interfaces/IEvents.hpp"
#include "controllers/AObjectController.hpp"
#include "EventHandler.hpp"


namespace engine {


  class EngineCore : public SceneManager, public WindowManager, public IEvents{

    public:

      EngineCore();
      ~EngineCore();

      void init();
      bool update();
      void addObjectControllerById(AObjectController *controller, int id);
      void addEvent(const string &event);

      // ======= INHERITED FROM PARENTS =======
      // bool loadScene(const string &scenename);
      // void unloadScene();
      // void deleteScene(const string &scenename);
      // void createSceneFromTmx(const string &scenename, 
      //                         const string &filepath);
      // void openWindow(const Vector2u &size, const string &title);
      // void openWindow(bool isFullScreen, const string &title);
      // void closeWindow();
      // void setWindowView(Vector2f center, Vector2f size);
      // void setFrameRateLimit(unsigned int value);

    private:

      // ======= INHERITED FROM PARENTS =======
      // RenderWindow window;
      // Scene *currScene;
      // vector<TileLayer*> *tileLayersList;
      // vector<ObjectLayer*> *objectLayersList;
      
      bool run;
      EventHandler eventHandler;
      
      void drawObjects();

      // ======= INHERITED FROM PARENTS =======
      // void getEvents();
      // void clearWindow();
      // void displayWindow();

      void onWindowClose();
      void onKeyPressed();

  };


}


#endif // ENGINECORE_H
