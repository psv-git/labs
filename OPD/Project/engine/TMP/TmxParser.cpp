#include "TmxParser.hpp"

using namespace engine;
//using namespace tinyxml2;


TmxParser::TmxParser() {
  scene = new Scene();
  isError = false;
}


TmxParser::~TmxParser() {
  if (scene)
    delete scene;
}

// ============================================================================

// Returns parent directory of given path;
std::string TmxParser::getParentDirectory(const std::string &filepath) {
  const size_t slashPos = filepath.find_last_of('/');
  std::string parentDir;
  if (slashPos != std::string::npos)
    parentDir = filepath.substr(0, slashPos);
  return parentDir;
}


// Joins two path fragments, e.g. directory path and filename
std::string TmxParser::joinPaths(const std::string &path, 
                                const std::string &subpath) {
  if (path.empty())
    return subpath;
  if (subpath.empty())
    return path;

  return path + DIR_SEPARATOR + subpath;
}


// Parses hex-encoded RGB like "6d9fb9"
sf::Color TmxParser::parseColor(const std::string &hexRGB) {
  char *pEnd = nullptr;
  const long hexValue = strtol(hexRGB.c_str(), &pEnd, 16);
  if (*pEnd != '\0')
    getError(hexRGB + " is not valid hex-encoded RGB color");
  const uint8_t red = uint8_t((hexValue >> 16) % 256);
  const uint8_t green = uint8_t((hexValue >> 8) % 256);
  const uint8_t blue = uint8_t(hexValue % 256);

  return sf::Color(red, green, blue);
}


// Parses float number
float TmxParser::parseFloat(const std::string &str) {
  char *pEnd = nullptr;
  const float value = strtof(str.c_str(), &pEnd);
  if (*pEnd != '\0')
    getError("'" + str + "' is not a float number");

  return value;
}


// Get message
void TmxParser::getMessage(const std::string &message) {
  std::cout << message << std::endl;
}


// Get error
void TmxParser::getError(const std::string &error) {
  getMessage(error);
  delete scene;
  scene = nullptr;
  isError = true;
}

// PARSER =====================================================================

Scene* TmxParser::parseTmxFile(const std::string &scenename, 
                              const std::string &filepath) {
  
  this->scenename = scenename;
  this->filepath = filepath;

  if (levelFile.LoadFile(filepath.c_str()) != XML_SUCCESS)
    getError("Loading level \"" + filepath + "\" failed.");
  else {
    tmxMap = levelFile.FirstChildElement("map");
    checkXmlElement(tmxMap);
  }

  getLayers();
  getObjectGroups();
  getObjects();
  

  setTilesetTexture();
  setScene();
  setSubRects();
  getLayers();
  getObjects();

  if (!isError)
    getMessage("Parse " + scenename + " already succesfully");

  return scene;
}

// ============================================================================

void TmxParser::checkXmlElement(XMLElement *element) {
  if (!element)
    getError("Error: xml element was not created.");
}


// Create xml elements
// void TmxParser::createXmlElements() {
//   if (!isError) {
//     tmxMap = levelFile.FirstChildElement("map");
//     if (!tmxMap)
//       getError("<map> element not found");
//   }
//   if (!isError) {
//     tmxLayer = tmxMap->FirstChildElement("layer");
//     if (tmxLayer) {
//       tmxLayerData = tmxLayer->FirstChildElement("data");
//       if (!tmxLayerData) {
//         getError("Bad map. No layer data information found.");
//       } else {
//         tmxTile = tmxLayerData->FirstChildElement("tile");
//         if (!tmxTile)
//           getError("Bad map. No tile information found.");
//       }
//     } 
//   }
//   if (!isError) {
//     tmxTileset = tmxMap->FirstChildElement("tileset");
//     tmxImage = tmxTileset->FirstChildElement("image");
//     tmxObjectGroup = tmxMap->FirstChildElement("objectgroup");
//     tmxObject = tmxObjectGroup->FirstChildElement("object");
//   }
// }


// Set tileset texture
void TmxParser::setTilesetTexture() {
  if (!isError) {
    sf::Image img;
    const std::string imageFilename = tmxImage->Attribute("source");
    const std::string imagePath = 
                      joinPaths(getParentDirectory(filepath), imageFilename);
    if (!img.loadFromFile(imagePath))
      getError("Failed to load tile sheet");
    if (!isError) {
      sf::Color matteColor = sf::Color(0, 0, 0, 0);
      if (tmxImage->Attribute("trans"))
        matteColor = parseColor(tmxImage->Attribute("trans"));
      img.createMaskFromColor(matteColor);
      tilesetTexture.loadFromImage(img);
      tilesetTexture.setSmooth(false);
      firstTileId = std::stoi(tmxTileset->Attribute("firstgid"));
    }
  }
}


// Set scene
void TmxParser::setScene() {
  if (!isError) {
    scene->setName(scenename);
    scene->setTilesCount(std::stoi(tmxMap->Attribute("width")),                                  std::stoi(tmxMap->Attribute("height")));
    scene->setTileSize(std::stoi(tmxMap->Attribute("tilewidth")),                               std::stoi(tmxMap->Attribute("tileheight")));
    scene->setProperties(getProperties(tmxMap));
  }
}


// Set sub rects
void TmxParser::setSubRects() {
  if (!isError) {
    const int columns = tilesetTexture.getSize().x / scene->getTileSize().x;
    const int rows = tilesetTexture.getSize().y / scene->getTileSize().y;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < columns; x++) {
        sf::IntRect rect;
        rect.top = y * scene->getTileSize().y;
        rect.height = scene->getTileSize().y;
        rect.left = x * scene->getTileSize().x;
        rect.width = scene->getTileSize().x;
        subRects.push_back(rect);
      }
    }
  }
}


// Get layers
void TmxParser::getLayers() {
  if (!isError) {
    while (tmxLayer) {
      // create new layer
      layer = new Layer();

      // set layer opacity
      int opacity = 255;
      if (tmxLayer->Attribute("opacity"))
        opacity = sf::Uint8(255 * parseFloat(tmxLayer->Attribute("opacity")));
  
      // set layer
      getLayerTiles(layer, opacity);
      if (tmxLayer->Attribute("name"))
        layer->setName(tmxLayer->Attribute("name"));
      layer->setOpacity(opacity);
      layer->setProperties(getProperties(tmxLayer));
  
      // add layer to scene
      scene->addLayer(layer);
  
      tmxLayer = tmxLayer->NextSiblingElement("layer");
    }
  }
}


// Get layer tiles
void TmxParser::getLayerTiles(Layer *layer, int opacity) {
  int x = 0;
  int y = 0;
  while (tmxTile) {
    const int tileGID = std::stoi(tmxTile->Attribute("gid"));
    const int subRectToUse = tileGID - firstTileId;

    if (subRectToUse >= 0) {
      sf::Sprite sprite;
      sprite.setTexture(tilesetTexture);
      sprite.setTextureRect(subRects[subRectToUse]);
      sprite.setPosition(static_cast<float>(x * scene->getTileSize().x),                        static_cast<float>(y * scene->getTileSize().y));
      sprite.setColor(sf::Color(255, 255, 255, opacity));
      layer->addTile(sprite);
    }

    tmxTile = tmxTile->NextSiblingElement("tile");

    x++;
    if (x >= scene->getTilesCount().x) {
      x = 0;
      y++;
      if (y >= scene->getTilesCount().y)
        y = 0;
    }
  }
}


// Get objects
void TmxParser::getObjects() {
  if (!isError) {
    while (tmxObjectGroup) {
      while (tmxObject) {
        // create new object
        object = new Object();
  
        float x = std::stof(tmxObject->Attribute("x"));
        float y = std::stof(tmxObject->Attribute("y"));
        float width = 0;
        float height = 0;
  
        sf::Sprite sprite;
        sprite.setTexture(tilesetTexture);
        sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
        sprite.setPosition(x, y);
  
        if (tmxObject->Attribute("width")) {
          width = std::stof(tmxObject->Attribute("width"));
          height = std::stof(tmxObject->Attribute("height"));
        } else {
          const size_t index = std::stoi(tmxObject->Attribute("gid")) -                                       firstTileId;
          width = static_cast<float>(subRects[index].width);
          height = static_cast<float>(subRects[index].height);
          sprite.setTextureRect(subRects[index]);
          sprite.setOrigin(0, height);
        }
  
        sf::FloatRect objectRect;
        objectRect.top = y;
        objectRect.left = x;
        objectRect.width = width;
        objectRect.height = height;
  
        // set object
        if (tmxObject->Attribute("name"))
          object->setName(tmxObject->Attribute("name"));
        if (tmxObject->Attribute("type"))
          object->setType(tmxObject->Attribute("type"));  
        object->setSprite(sprite);
        object->setRect(objectRect);
        object->setProperties(getProperties(tmxObject));
  
        // add object to scene
        scene->addObject(object);

        tmxObject = tmxObject->NextSiblingElement("object");
      }
  
      tmxObjectGroup = tmxObjectGroup->NextSiblingElement("objectgroup");
    }
  }
}


// Get properties
std::map<std::string, std::string> TmxParser::getProperties(
                                                XMLElement *element) {
  std::map<std::string, std::string> result;
  if (properties = element->FirstChildElement("properties")) {
    property = properties->FirstChildElement("property");
    while (property) {
      result.insert(std::pair<std::string, std::string>(
                property->Attribute("name"), property->Attribute("value")));
      property = property->NextSiblingElement("property");
    }
  }
  return result;
}
