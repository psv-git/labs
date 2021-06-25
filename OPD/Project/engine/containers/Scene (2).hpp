#ifndef SCENE_H
#define SCENE_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "Object.hpp"
#include "TileLayer.hpp"
#include "ObjectLayer.hpp"


namespace engine {


  class Scene {

    public:

      Scene();
      ~Scene();

      vector<TileLayer*>* getSceneTileLayers();
      vector<ObjectLayer*>* getSceneObjectLayers();

      const string& getName();
      Vector2f getSize();
      Vector2i getTileSize();
      Vector2i getTilesCount();
      const Texture& getTilesetTexture();

      void setName(const string &value);
      void setTileSize(int width, int height);
      void setTilesCount(int width, int height);
      void setTilesetTexture(const Texture &value);
      void setFirstFreeId(int value);
      void setBackgroundColor(const Color &value);
      void addProperties(const map<string, string> &value);
      
      void addObject(Object *object);
      void addTileLayer(TileLayer *layer);
      void addObjectLayer(ObjectLayer *layer);

    private:
    
      string name;

      // first free id for new object
      int firstFreeId;

      int tileWidth;
      int tileHeight;
      int widthTilesCount;
      int heightTilesCount;

      Color backgroundColor;
      Texture tilesetTexture;
      
      map<string, string> properties;
      
      // objects prot container
      vector<Object*> objectsList;
      // tile layers container
      vector<TileLayer*> tileLayersList;
      // object layers container
      vector<ObjectLayer*> objectLayersList;

      void deleteData();

  };


}


#endif // SCENE_H
