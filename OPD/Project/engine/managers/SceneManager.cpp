#include "SceneManager.hpp"

using namespace engine;


SceneManager::SceneManager() {
  currScene = nullptr;
  tileLayersList = nullptr;
  objectLayersList = nullptr;
}


SceneManager::~SceneManager() {}

// ============================================================================

// delete scene by name
void SceneManager::deleteScene(const string &scenename) {
  auto it = scenesList.find(scenename);
  if (it != scenesList.end()) {
    if (it->second == currScene)
      unloadScene();
    delete it->second;
  } else {
    cout << "Scene " << scenename << " not fount to delete." << endl;
  }
}


// delete maps, layers, objects
void SceneManager::deleteScenes() {
  for(auto elem : scenesList)
    delete elem.second;
  scenesList.clear();
  currScene = nullptr;
}

// ============================================================================

// load game scene
bool SceneManager::loadScene(const string &scenename) {
  currScene = nullptr;

  // find target scene
  auto it = scenesList.find(scenename);
  if (it != scenesList.end()) {
    currScene = it->second;
    tileLayersList = currScene->getSceneTileLayers();
    objectLayersList = currScene->getSceneObjectLayers();
  }
  
  // load target scene
  if (currScene) {
    cout << "Scene " + scenename + " was loaded successfuly." << endl;
    return true;
  } else {
    cout << "Scene " + scenename + " not found." << endl;
    return false;
  }
}


// unload game scene
void SceneManager::unloadScene() {
  currScene = nullptr;
  tileLayersList = nullptr;
  objectLayersList = nullptr;
}


// get scene from tmx file
void SceneManager::createSceneFromTmx(const string &scenename, 
                                      const string &filepath) {
  // if whis scene already exist
  auto it = scenesList.find(scenename);
  if (it != scenesList.end()) {
    cout << "Scene " << scenename << " already exist." << endl;
    return;
  }

  // parse tmx file
  TmxParser parser;
  Scene *scene = parser.createScene(scenename, filepath);
  if (scene) {
    scenesList.insert(pair(scenename, scene));
    cout << "Scene " << scenename << " was created successfully." << endl;
  }
}
