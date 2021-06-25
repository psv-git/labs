#include "ObjectLayer.hpp"

using namespace engine;


ObjectLayer::ObjectLayer() {
  visible = true;
  opacity = 255;
}


ObjectLayer::~ObjectLayer() {}

// ============================================================================

// delete layer objects
void ObjectLayer::deleteData() {
  for(Object *object : objectsList)
    delete object;
}

// draw =======================================================================

void ObjectLayer::draw(RenderTarget &target) const {
  if (visible) {
    for (Object *object : objectsList)
      target.draw(*object);
  }
}

// getters ====================================================================

const string& ObjectLayer::getName() {
  return name;
}


Uint8 ObjectLayer::getOpacity() {
  return opacity;
}

Object* ObjectLayer::findObject(int id) {
  Object* obj = nullptr;
  for (Object *object : objectsList) {
    if (object->getId() == id) {
      obj = object;
      break;
    }
  }

  return obj;
}

// setters ====================================================================

void ObjectLayer::setName(const string &value) {
  name = value;
}

void ObjectLayer::setVisible(bool value) {
  visible = value;
}


void ObjectLayer::setOpacity(Uint8 value) {
  opacity = value;
}


void ObjectLayer::addProperties(const map<string, string> &value) {
  for (const auto &elem : value)
    properties.insert(elem);
}
  

void ObjectLayer::addObject(Object *object) {
  objectsList.push_back(object);
}
