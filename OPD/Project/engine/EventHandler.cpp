#include "EventHandler.hpp"

using namespace engine;


EventHandler::EventHandler() {}


EventHandler::~EventHandler() {}

// ============================================================================

void EventHandler::addListner(IEvents *listner, const string &event) {
  auto it = listnersList.find(event);
  if (it == listnersList.end()) {
    vector<IEvents*> newList;
    newList.push_back(listner);
    listnersList.insert(pair(event, newList));
  } else {
    it->second.push_back(listner);
  }
}


void deleteListner(IEvents *listner) {}


void EventHandler::addEvent(const string &event) {
  eventsList.push_back(event);
}


void EventHandler::update(RenderWindow &window) {
  while (window.pollEvent(event)) {
    switch (event.type) {
      case Event::Closed :
        addEvent("windowClosed");
        break;
      case Event::Resized :
        addEvent("windowResized");
        break;
      case Event::LostFocus :
        addEvent("windowLostFocus");
        break;
      case Event::GainedFocus :
        addEvent("windowGainedFocus");
        break;
      case Event::TextEntered :
        addEvent("windowTextEntered");
        break;
      case Event::KeyPressed :
        addEvent("windowKeyPressed");
        break;
      case Event::KeyReleased :
        addEvent("windowKeyRleased");
        break;
      case Event::MouseWheelMoved :
        addEvent("windowMouseWheelMoved");
        break;
      case Event::MouseWheelScrolled :
        addEvent("windowMouseWheelScrolled");
        break;
      case Event::MouseButtonPressed :
        addEvent("windowMouseButtonPressed");
        break;
      case Event::MouseButtonReleased :
        addEvent("windowMouseButtonReleased");
        break;
      case Event::MouseMoved :
        addEvent("windowMouseMoved");
        break;
      case Event::MouseEntered :
        addEvent("windowMouseEntered");
        break;
      case Event::MouseLeft :
        addEvent("windowMouseLeft");
        break;
      case Event::JoystickButtonPressed :
        addEvent("windowJoystickButtonPressed");
        break;
      case Event::JoystickButtonReleased :
        addEvent("windowJoystickButtonReleased");
        break;
      case Event::JoystickMoved :
        addEvent("windowJoystickMoved");
        break;
      case Event::JoystickConnected :
        addEvent("windowJoystickConnected");
        break;
      case Event::JoystickDisconnected :
        addEvent("windowJoystickDisconnected");
        break;
      case Event::TouchBegan :
        addEvent("windowTouchBegan");
        break;
      case Event::TouchMoved :
        addEvent("windowTouchMoved");
        break;
      case Event::TouchEnded :
        addEvent("windowTouchEnded");
        break;
      case Event::SensorChanged :
        addEvent("windowSensorChanged");
        break;
      default:
        break;
    }
  }
  for (const string &event : eventsList) {
    auto it = listnersList.find(event);
    if (it != listnersList.end())
      for (IEvents *listner : it->second)
        listner->addEvent(event);
  }
  eventsList.clear();
}
