#include "ObjectController.hpp"

using namespace engine;


ObjectController::ObjectController(EventHandler *eventHandler) {
  this->eventHandler = eventHandler;
  eventHandler->addListner(this, "windowKeyPressed");
}


ObjectController::~ObjectController() {}

// ============================================================================

void ObjectController::addEvent(const string &event) {
  if (event == "windowKeyPressed")
    onKeyPressed();
}


void ObjectController::onKeyPressed() {
  if (!object) return;

  if (Keyboard::isKeyPressed(Keyboard::Left))
    move(-2, 0);
  if (Keyboard::isKeyPressed(Keyboard::Right))
    move(2, 0);
  if (Keyboard::isKeyPressed(Keyboard::Up))
    move(0, -2);
  if (Keyboard::isKeyPressed(Keyboard::Down))
    move(0, 2);

  object->setTransform(transform);
}
