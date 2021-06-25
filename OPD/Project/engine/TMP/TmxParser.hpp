#ifndef TMXPARSER_H
#define TMXPARSER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "tinyxml2.hpp"
#include "../containers/Scene.hpp"
#include "../containers/Layer.hpp"
#include "../containers/Object.hpp"
#include "tinyxml2.hpp"


namespace engine {

  using namespace tinyxml2;

  class TmxParser {

    private:
      // xml
      XMLDocument levelFile;
      XMLElement *tmxMap;
      XMLElement *tmxTileset;
      XMLElement *tmxImage;
      XMLElement *tmxLayer;
      XMLElement *tmxLayerData;
      XMLElement *tmxTile;
      XMLElement *tmxObjectGroup;
      XMLElement *tmxObject;
      XMLElement *properties;
      XMLElement *property;

      Scene *scene;
      Layer *layer;
      Object *object;

      bool isError;
      std::string scenename;
      std::string filepath;
      int firstTileId;
      sf::Texture tilesetTexture;
      std::vector<sf::IntRect> subRects;

      void getMessage(const std::string &message);
      void getError(const std::string &error);
      float parseFloat(const std::string &str);
      sf::Color parseColor(const std::string &hexRGB);
      std::string getParentDirectory(const std::string &filepath);
      std::string joinPaths(const std::string &path, 
                            const std::string &subpath);

      void createXmlElements();
      void setTilesetTexture();
      void setScene();
      void setSubRects();
      void getLayers();
      void getLayerTiles(Layer *layer, int opacity);
      void getObjects();
      std::map<std::string, std::string> getProperties(XMLElement *element);

    public:
      TmxParser();
      ~TmxParser();

      Scene* parseTmxFile(const std::string &scenename, 
                        const std::string &filepath);

  };


}


#endif // TMXPARSER_H
