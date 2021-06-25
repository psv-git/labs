#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class WindowManager {
    
    public:
    
      WindowManager();
      virtual ~WindowManager() = 0;

      void openWindow(const Vector2u &size, const string &title);
      void openWindow(bool fullscreen, const string &title);
      void closeWindow();

      void setWindowView(const Vector2f &center, const Vector2f &size);
      void setFrameRateLimit(unsigned int value);

    protected:

      RenderWindow window;

      void clearWindow();
      void displayWindow();

    private:

      VideoMode videoMode;

  };


}


#endif // WINDOWMANAGER_H
