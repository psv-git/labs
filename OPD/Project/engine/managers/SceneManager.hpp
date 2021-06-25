#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "../parsers/TmxParser.hpp"
#include "../containers/Scene.hpp"


namespace engine {


  class SceneManager {

    public:
      
      SceneManager();
      virtual ~SceneManager() = 0;

      bool loadScene(const string &scenename);
      void unloadScene();
      void deleteScene(const string &scenename);

      void createSceneFromTmx(const string &scenename, 
                              const string &filepath);

    protected:
      
      // current scene
      Scene *currScene;

      // current scene layers
      vector<TileLayer*> *tileLayersList;
      vector<ObjectLayer*> *objectLayersList;

      // delete all scenes
      void deleteScenes();

    private:
    
      // scenes container; pair "scenename/scene"
      map<string, Scene*> scenesList;

  };


}


#endif // SCENEMANAGER_H
