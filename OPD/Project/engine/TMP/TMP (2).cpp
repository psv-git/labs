// windowsList.insert(std::pair<int, WindowContainer*>(id, windowContainer));

// int CoreManager::getId() {
//     std::srand(std::time(0));
//     int newId = std::rand() + 1;
//     while (idList.find(newId) != idList.end()) {
//         newId = std::rand() + 1;
//     }
//     idList.insert(newId);
//     return newId;
// }

// typedef std::vector<std::reference_wrapper<sf::Drawable>> ObjContType;

// void ApplicationManager::ShaderExperimentInit() {
//     Vector2u wSize = coreManager->GetWindowSize();
//     texture.create(wSize.x, wSize.y);
//     sprite.setTexture(texture);
//     shader.loadFromFile(FIRE_SHADER_PATH, Shader::Fragment);
//     shader.setUniform("resolution", Vector2f(wSize.x / 2, wSize.y / 2));
//     clock.restart(); 
// }


// void ApplicationManager::ShaderExperimentRun() {
//     shader.setUniform("time", clock.getElapsedTime().asSeconds());
//     Vector2i mousePos = coreManager->GetMousePosition();
//     Vector2u wSize = coreManager->GetWindowSize();
//     shader.setUniform("mouse", Vector2f(mousePos.x, mousePos.y / 2));
//     coreManager->DrawObject(sprite, &shader);
// }

// const std::string BALL_TEXTURE_PATH = "resources/images/ball.png";
  // const std::string TREE1_TEXTURE_PATH = "resources/images/tree1.png";
  // const std::string TREE2_TEXTURE_PATH = "resources/images/tree2.png";
  // const std::string TREE3_TEXTURE_PATH = "resources/images/tree3.png";

  // const std::string FIRE_SHADER_PATH = "resources/shaders/fire.glsl";


  // void WindowManager::deleteObjects() {
  //   for (int i = 0; i < delList.size(); i++)
  //     drawList.erase(drawList.find(delList[i]));
  //   delList.clear();
  // }

  // void CoreManager::addObject(AObject *obj, int layer) {
//   drawList.insert(std::pair<int, AObject*>(layer, obj));
// }
// void CoreManager::addObject(IEvents *obj) {
//   eventManager->addObject(obj);
// }
// void CoreManager::deleteObject(AObject *obj, int layer) {
//   for (auto it = drawList.lower_bound(layer); it != drawList.end(); it++)
//     if ((*it).second == obj) {
//       drawList.erase(it);
//       break;
//     }
// }
// void CoreManager::deleteObject(IEvents *obj) {
//   eventManager->deleteObject(obj);
// }



// void onWindowClose();
      // void onWindowResize();
      // void onWindowLostFocus();
      // void onWindowGainedFocus();
      // void onTextEntered();
      // void onKeyPressed();
      // void onKeyReleased();
      // void onMouseWheelMoved();
      // void onMouseWheelScrolled();
      // void onMouseButtonPressed();
      // void onMouseButtonReleased();
      // void onMouseMoved();
      // void onMouseEntered();
      // void onMouseLeft();
      // void onJoystickButtonPressed();
      // void onJoystickButtonReleased();
      // void onJoystickMoved();
      // void onJoystickConnected();
      // void onJoystickDisconnected();
      // void onTouchBegan();
      // void onTouchMoved();
      // void onTouchEnded();
      // void onSensorChanged();

// void EventManager::addSubscriber(IEvents *subscriber) {
//   subscribersList.push_back(subscriber);
// }


// void EventManager::deleteSubscriber(IEvents *subscriber) {
//   for (auto it = subscribersList.begin(); it != subscribersList.end(); it++)
//     if (*it == subscriber)
//       subscribersList.erase(it);
// }


// void EventManager::addEvent(Event::EventType event) {
//   eventsList.push_back(event);
// }


// check actual window events
// void EventManager::update() {
//   for (auto type : eventsList) {
//     switch (type) {
//       case Event::Closed :
//         EventManager::onWindowClose();
//         break;
//       case Event::Resized :
//         EventManager::onWindowResize();
//         break;
//       case Event::LostFocus :
//         EventManager::onWindowLostFocus();
//         break;
//       case Event::GainedFocus :
//         EventManager::onWindowGainedFocus();
//         break;
//       case Event::TextEntered :
//         EventManager::onTextEntered();
//         break;
//       case Event::KeyPressed :
//         EventManager::onKeyPressed();
//         break;
//       case Event::KeyReleased :
//         EventManager::onKeyReleased();
//         break;
//       case Event::MouseWheelMoved :
//         EventManager::onMouseWheelMoved();
//         break;
//       case Event::MouseWheelScrolled :
//         EventManager::onMouseWheelScrolled();
//         break;
//       case Event::MouseButtonPressed :
//         EventManager::onMouseButtonPressed();
//         break;
//       case Event::MouseButtonReleased :
//         EventManager::onMouseButtonReleased();
//         break;
//       case Event::MouseMoved :
//         EventManager::onMouseMoved();
//         break;
//       case Event::MouseEntered :
//         EventManager::onMouseEntered();
//         break;
//       case Event::MouseLeft :
//         EventManager::onMouseLeft();
//         break;
//       case Event::JoystickButtonPressed :
//         EventManager::onJoystickButtonPressed();
//         break;
//       case Event::JoystickButtonReleased :
//         EventManager::onJoystickButtonReleased();
//         break;
//       case Event::JoystickMoved :
//         EventManager::onJoystickMoved();
//         break;
//       case Event::JoystickConnected :
//         EventManager::onJoystickConnected();
//         break;
//       case Event::JoystickDisconnected :
//         EventManager::onJoystickDisconnected();
//         break;
//       case Event::TouchBegan :
//         EventManager::onTouchBegan();
//         break;
//       case Event::TouchMoved :
//         EventManager::onTouchMoved();
//         break;
//       case Event::TouchEnded :
//         EventManager::onTouchEnded();
//         break;
//       case Event::SensorChanged :
//         EventManager::onSensorChanged();
//         break;
//       default:
//         break;
//     }
//   }
//   eventsList.clear();
// }

// WINDOW EVENTS ==============================================================

// void EventManager::onWindowClose() {
//   for (IEvents *subs : subscribersList)
//     subs->onKeyPressed();
// }


// void EventManager::onWindowResize() {}
// void EventManager::onWindowLostFocus() {}
// void EventManager::onWindowGainedFocus() {}
// void EventManager::onTextEntered() {}

// KEYBOARD EVENTS ============================================================

// void EventManager::onKeyPressed() {
//   for (IEvents *subs : subscribersList)
//     subs->onKeyPressed();
// }


// void EventManager::onKeyReleased() {
//   for (IEvents *subs : subscribersList)
//     subs->onKeyPressed();
// }

// MOUSE EVENTS ===============================================================

// void EventManager::onMouseWheelMoved() {}
// void EventManager::onMouseWheelScrolled() {}
// void EventManager::onMouseButtonPressed() {}
// void EventManager::onMouseButtonReleased() {}
// void EventManager::onMouseMoved() {}
// void EventManager::onMouseEntered() {}
// void EventManager::onMouseLeft() {}

// ============================================================================

// void EventManager::onJoystickButtonPressed() {}
// void EventManager::onJoystickButtonReleased() {}
// void EventManager::onJoystickMoved() {}
// void EventManager::onJoystickConnected() {}
// void EventManager::onJoystickDisconnected() {}
// void EventManager::onTouchBegan() {}
// void EventManager::onTouchMoved() {}
// void EventManager::onTouchEnded() {}
// void EventManager::onSensorChanged() {}
