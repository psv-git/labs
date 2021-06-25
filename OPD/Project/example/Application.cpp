#include "Application.hpp"

using namespace engine;


Application::Application() {}


Application::~Application() {}

// ============================================================================

path Application::getExecutableDir() {
  #if __linux__
    char pathUtf8[4096] = { 0 };
    const ssize_t readCount = readlink("/proc/self/exe", pathUtf8, 
                                        size(pathUtf8));
    if (readCount < 0) {
      throw runtime_error("cannot read current executable path");
    }
    return path(pathUtf8).parent_path();
  #else
    #error getExecutableDir is not implemented for this platform
  #endif
}


path Application::getResourcesDir() {
  return getExecutableDir().parent_path() / "example" / "resources";
}

// ============================================================================

void Application::run() {

  EventHandler eventHandler;
  EngineCore manager();
  ObjectController controller();

  manager.openWindow(true, "Main");
  manager.setFrameRateLimit(60);
  manager.setWindowView(Vector2f(683, 384), Vector2f(1366, 768));
  manager.createSceneFromTmx("game", (getResourcesDir() / "scenes" /                                    "game.tmx").native());
  manager.loadScene("game");
  manager.addObjectControllerById(&controller, 316);

  // game loop
  while (manager.update()) {}

}
