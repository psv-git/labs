#include "AObjectController.hpp"

using namespace engine;


AObjectController::AObjectController() {
  object = nullptr;
  eventHandler = nullptr;
}


AObjectController::~AObjectController() {}

// ============================================================================

void AObjectController::setObject(Object *obj) {
  object = obj;
  transform = object->getTransform();
}


void AObjectController::setEventHandler(EventHandler *eventHandler) {
  this->eventHandler = eventHandler;
}

// ============================================================================

void AObjectController::move(float x, float y) {
  transform.translate(x, y);
}


void AObjectController::rotate(float angle) {
  transform.rotate(angle);
}
