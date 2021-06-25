#include "EngineCore.hpp"

using namespace engine;


EngineCore::EngineCore() {
  init();
}


EngineCore::~EngineCore() {
  SceneManager::deleteScenes();
}

// ============================================================================

void EngineCore::init() {
  run = true;
  eventHandler.addListner(this, "windowClosed");
  eventHandler.addListner(this, "windowKeyPressed");
}


// application loop
bool EngineCore::update() {
  if (run) {
    WindowManager::clearWindow();
    drawObjects();
    WindowManager::displayWindow();
    eventHandler.update(window);
  }
  
  return run;
}

// ============================================================================

void EngineCore::drawObjects() {
  if (currScene) {
    for (TileLayer *layer : *tileLayersList)
      layer->draw(window);
    for (ObjectLayer *layer : *objectLayersList)
      layer->draw(window);
  }
}

// ============================================================================

void EngineCore::addObjectControllerById(AObjectController *controller,int id){
  if (currScene) {
    for (ObjectLayer *layer : *objectLayersList) {
      Object *obj = layer->findObject(id);
      if (obj) {
        controller->setObject(obj);
        controller->setEventHandler(&eventHandler);
        break;
      }
    }
  }
}

// event handlers =============================================================

void EngineCore::addEvent(const string &event) {
  if (event == "windowClosed")
    onWindowClose();
  if (event == "windowKeyPressed")
    onKeyPressed();
}


void EngineCore::onWindowClose() {
  WindowManager::closeWindow();
  run = false;
}


void EngineCore::onKeyPressed() {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    WindowManager::closeWindow();
    run = false;
  }
}
