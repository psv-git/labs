#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "Object.hpp"


namespace engine {


  class ObjectLayer {

    public:

      ObjectLayer();
      ~ObjectLayer();

      void draw(RenderTarget &target) const;
      Object* findObject(int id);

      const string& getName();
      Uint8 getOpacity();

      void setName(const string &value);
      void setOpacity(Uint8 value);
      void setVisible(bool value);
      void addProperties(const map<string, string> &value);

      void addObject(Object *object);

    private:

      string name;

      bool visible;
      Uint8 opacity;

      vector<Object*> objectsList;

      map<string, string> properties;

      void deleteData();

  };


}


#endif // OBJECTLAYER_H
