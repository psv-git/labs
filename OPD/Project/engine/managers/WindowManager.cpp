#include "WindowManager.hpp"

using namespace engine;


WindowManager::WindowManager() {}


WindowManager::~WindowManager() {}

// window =====================================================================

void WindowManager::openWindow(const Vector2u &size, 
                                const string &title) {
  videoMode = VideoMode(size.x, size.y, DEFAULT_BIT_PER_PIXEL);
  window.create(videoMode, title, sf::Style::Default);
}


void WindowManager::openWindow(bool fullscreen, 
                                const string &title) {
  videoMode = VideoMode::getDesktopMode();
  if (fullscreen)
    window.create(videoMode, title, sf::Style::Fullscreen);
  else
    window.create(videoMode, title, sf::Style::Default);
}


void WindowManager::closeWindow() {
  window.close();
}


void WindowManager::clearWindow() {
  window.clear();
}


void WindowManager::displayWindow() {
  window.display();
}

// ============================================================================

void WindowManager::setFrameRateLimit(unsigned int value) {
  window.setFramerateLimit(value);
}


void WindowManager::setWindowView(const Vector2f &center, 
                                  const Vector2f &size) {
  View view(center, size);
  window.setView(view);
}
