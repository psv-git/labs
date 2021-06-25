#ifndef TMXPARSER_H
#define TMXPARSER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "../containers/Scene.hpp"
#include "../containers/TileLayer.hpp"
#include "../containers/ObjectLayer.hpp"
#include "../containers/Tile.hpp"
#include "../containers/Object.hpp"
#include "tinyxml2.hpp"


namespace engine {

  using namespace tinyxml2;

  class TmxParser {

    public:
      TmxParser();
      ~TmxParser();

      Scene* createScene(string scenename, string filepath);

    private:

      XMLDocument levelFile;
      XMLElement *tmxScene;

      bool isError;
      Scene *scene;

      string scenename;
      string filepath;
      string attribute;
      int firstTileId;
      Texture tilesetTexture;
      vector<IntRect> subRects;
      vector<Object*> objectsList;
      map<string, string> properties;

      void getMessage(const string &message);
      void getError(const string &error);
      float parseFloat(string str);
      Color parseColor(string hexRGB);
      string getParentDirectory(string filepath);
      string joinPaths(string path, string subpath);
      bool getProperties(XMLElement *element);
      bool getAttribute(XMLElement *tmxElement, const char* tmxAttr);

      void setScene();
      bool setSceneTileset();
      void setSceneObjects();
      void setSceneTileLayers();
      void setSceneObjectLayers();

  };


}


#endif // TMXPARSER_H
