#include "TmxParser.hpp"

using namespace engine;


TmxParser::TmxParser() {
  scene = nullptr;
  isError = false;
}


TmxParser::~TmxParser() {}

// ============================================================================

// returns parent directory of given path
string TmxParser::getParentDirectory(string filepath) {
  const size_t slashPos = filepath.find_last_of('/');
  string parentDir = "";
  if (slashPos != string::npos)
    parentDir = filepath.substr(0, slashPos);
  return parentDir;
}


// joins two path fragments, e.g. directory path and filename
string TmxParser::joinPaths(string path, string subpath) {
  if (path.empty())
    return subpath;
  if (subpath.empty())
    return path;

  return path + DIR_SEPARATOR + subpath;
}


// parses hex-encoded RGB like "6d9fb9"
Color TmxParser::parseColor(string hexRGB) {
  char *pEnd = nullptr;
  const long hexValue = strtol(hexRGB.c_str() + 1, &pEnd, 16);
  if (*pEnd != '\0')
    getError("Parse error: '" + hexRGB + "' is not valid RGB color.");
  const uint8_t red = uint8_t((hexValue >> 16) % 256);
  const uint8_t green = uint8_t((hexValue >> 8) % 256);
  const uint8_t blue = uint8_t(hexValue % 256);

  return Color(red, green, blue);
}


// parse float number
float TmxParser::parseFloat(string str) {
  char *pEnd = nullptr;
  const float value = strtof(str.c_str(), &pEnd);
  if (*pEnd != '\0')
    getError("Parse error: '" + str + "' is not a float number.");

  return value;
}


// get message
void TmxParser::getMessage(const string &message) {
  cout << message << endl;
}


// get error
void TmxParser::getError(const string &error) {
  getMessage(error);
  if (scene)
    delete scene;
  scene = nullptr;
  isError = true;
}


bool TmxParser::getAttribute(XMLElement *tmxElement, const char* tmxAttr) { 
  if (!tmxElement->Attribute(tmxAttr))
    return false;

  attribute = tmxElement->Attribute(tmxAttr);
  return true;
}


// get element properties
bool TmxParser::getProperties(XMLElement *tmxElement) {
  properties.clear();
  XMLElement *tmxProperties = tmxElement->FirstChildElement("properties");
  if (!tmxProperties)
    return false;
  else {
    XMLElement *tmxProperty = tmxProperties->FirstChildElement("property");
    while (tmxProperty) {
      properties.insert(pair<string, string>(tmxProperty->Attribute("name"),                                        tmxProperty->Attribute("value")));
      tmxProperty = tmxProperty->NextSiblingElement("property");
    }
    return true;
  }
}

// parser =====================================================================

Scene* TmxParser::createScene(string scenename, string filepath) {
  this->scenename = scenename;
  this->filepath = filepath;

  // load level file
  if (levelFile.LoadFile(filepath.c_str()) != XML_SUCCESS)
    getError("Parse error: loading level '" + filepath + "' failed.");

  setScene();
  setSceneObjects();
  setSceneTileLayers();
  setSceneObjectLayers();

  return scene;
}


// create and set scene
void TmxParser::setScene() {
  if (!isError) {
    tmxScene = levelFile.FirstChildElement("map");
    if (!tmxScene) {
      getError("Parse error: <map> element not found.");
      return;
    }

    //create new scene
    scene = new Scene();

    // set scene
    scene->setName(scenename);

    // set tiles count
    Vector2i tilesCount;
    if (getAttribute(tmxScene, "width")) {
      tilesCount.x = stoi(attribute);
    } else {
      getError("Parse error: bad map, width not found.");
      return;
    }
    if (getAttribute(tmxScene, "height")) {
      tilesCount.y = stoi(attribute);  
    } else {
      getError("Parse error: bad map, height not found.");
      return;
    }
    scene->setTilesCount(tilesCount.x, tilesCount.y);
    
    // set tile size
    Vector2i tileSize;
    if (getAttribute(tmxScene, "tilewidth")) {
      tileSize.x = stoi(attribute);
    } else {
      getError("Parse error: bad map, tile width not found.");
      return;
    }
    if (getAttribute(tmxScene, "tileheight")) {
      tileSize.y = stoi(attribute);
    } else {
      getError("Parse error: bad map, tile height not found.");
      return;
    }
    scene->setTileSize(tileSize.x, tileSize.y);

    // set first free id
    int firstFreeId;
    if (getAttribute(tmxScene, "nextobjectid")) {
      firstFreeId = stoi(attribute);
    } else {
      getError("Parse error: bad map, first free id not found.");
      return;
    }
    scene->setFirstFreeId(firstFreeId);

    // set background color
    Color color;
    if (getAttribute(tmxScene, "backgroundcolor")) {
      color = parseColor(attribute);
      scene->setBackgroundColor(color);
    }

    // set properties
    if (getProperties(tmxScene))
      scene->addProperties(properties);

    // set scene tileset
    if (setSceneTileset())
      scene->setTilesetTexture(tilesetTexture);
  }
}


// create tileset texture and work data
bool TmxParser::setSceneTileset() {
  XMLElement *tmxTileset = tmxScene->FirstChildElement("tileset");
  if (!tmxTileset) {
    getError("Parse error: tileset not found.");
    return false;
  }
  XMLElement *tmxImage = tmxTileset->FirstChildElement("image");
  if (!tmxImage) {
    getError("Parse error: tileset image not found.");
    return false;
  }

  // get image source
  string imagePath;
  if (getAttribute(tmxImage, "source")) {
    imagePath = joinPaths(getParentDirectory(filepath), attribute);
  } else {
    getError("Parse error: image source not found.");
    return false;
  }

  // get image
  Image image;
  if (!image.loadFromFile(imagePath)) {
    getError("Parse error: failed to load tileset image");
    return false;
  }

  // get image color
  Color color = Color(0, 0, 0, 0);
  if (getAttribute(tmxImage, "trans")) {
    color = parseColor(attribute);
  }
  image.createMaskFromColor(color);

  // set tileset texture
  tilesetTexture.loadFromImage(image);
  tilesetTexture.setSmooth(false);

  // get first tile id
  if (getAttribute(tmxTileset, "firstgid")) {
    firstTileId = stoi(attribute);
  } else {
    getError("Parse error: firstgid not found.");
    return false;
  }

  // set texture sub rects
  int cols = tilesetTexture.getSize().x / scene->getTileSize().x;;
  int rows = tilesetTexture.getSize().y / scene->getTileSize().y;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int left = x * scene->getTileSize().x;
      int top = y * scene->getTileSize().y;
      int width = scene->getTileSize().x;
      int height = scene->getTileSize().y;
      IntRect rect(left, top, width, height);
      subRects.push_back(rect);
    }
  }

  return true;
}


// create objects prototipes
void TmxParser::setSceneObjects() {
  if (!isError) {
    XMLElement *tmxTile = tmxScene->FirstChildElement("tile");
    while (tmxTile) {
      XMLElement *tmxObjectGroup = tmxTile->FirstChildElement("objectgroup");
      if (tmxObjectGroup) {
        // create new object
        Object *object = new Object();

        // set object id
        int objectId;
        if (getAttribute(tmxTile, "id")) {
          objectId = stoi(attribute);
        } else {
          getError("Parse error: object id not found.");
          return;
        }
        object->setId(objectId);

        // set object position & rotation
        float x = 0, y = 0, angle = 0;
        XMLElement *tmxObject = tmxObjectGroup->FirstChildElement("object");
        if (tmxObject) {
          if (getAttribute(tmxObject, "x"))
            x = stof(attribute);
          if (getAttribute(tmxObject, "y"))
            y = stof(attribute); 
          if (getAttribute(tmxObject, "rotation"))
            angle = stof(attribute);
        }
        object->setPosition(x, y);
        object->setRotation(angle);

        // set tiles rect
        XMLElement *tmxAnimation = tmxTile->FirstChildElement("animation");
        if (tmxAnimation) {
          XMLElement *tmxFrame = tmxTile->FirstChildElement("frame");
          while (tmxFrame) {
            if (getAttribute(tmxFrame, "tileId")) {
              int tileId = stoi(attribute);
              if (getAttribute(tmxFrame, "duration")) {
                float duration = stof(attribute);
                object->addTileRect(make_pair(subRects[tileId], duration));
              }
            }
            tmxFrame = tmxFrame->NextSiblingElement("frame");
          }
        } else {
          object->addTileRect(make_pair(subRects[objectId], 0));
        }

        // set object texture
        object->setTilesetTexture(scene->getTilesetTexture());

        // set object name
        if (getAttribute(tmxObject, "name"))
          object->setName(attribute);

        // set object visible
        if (getAttribute(tmxObjectGroup, "visible"))
          object->setVisible(static_cast<bool>(stoi(attribute)));

        // set object properties
        if (getProperties(tmxObjectGroup))
          object->addProperties(properties);

        // add object data to scene
        scene->addObject(object);
        // add object data to temp parser list
        objectsList.push_back(object);
      }

      tmxTile = tmxScene->NextSiblingElement("tile");
    }
  }
} 


// layers contain only static tiles
void TmxParser::setSceneTileLayers() {
  if (!isError) {
    XMLElement *tmxTileLayer = tmxScene->FirstChildElement("layer");
    while (tmxTileLayer) {
      // check layers data
      XMLElement *tmxLayerData = tmxTileLayer->FirstChildElement("data");
      if (!tmxLayerData) {
        getMessage("Parse warning: no layer data information found.");
        tmxTileLayer = tmxTileLayer->NextSiblingElement("layer");
        continue;
      }
      // check layers tiles
      XMLElement *tmxTile = tmxLayerData->FirstChildElement("tile");
      if (!tmxTile) {
        getMessage("Parse warning: no layer tiles information found.");
        tmxTileLayer = tmxTileLayer->NextSiblingElement("layer");
        continue;
      }

      // create new tiles layer
      TileLayer *tileLayer = new TileLayer();

      // set layer size
      float layerWidth = scene->getTilesCount().x;
      float layerHeight = scene->getTilesCount().y;
      if (getAttribute(tmxTileLayer, "width"))
        layerWidth = stoi(attribute);
      if (getAttribute(tmxTileLayer, "height"))
        layerHeight = stoi(attribute);

      // set layer opacity
      Uint8 opacity = 255;
      if (getAttribute(tmxTileLayer, "opacity"))
        opacity *= stof(attribute);
      tileLayer->setOpacity(opacity);

      // set layer name
      if (getAttribute(tmxTileLayer, "name"))
        tileLayer->setName(attribute);

      // set layer visible
      if (getAttribute(tmxTileLayer, "visible"))
        tileLayer->setVisible(static_cast<bool>(stoi(attribute)));
      
      // set layer properties
      if (getProperties(tmxTileLayer))
        tileLayer->addProperties(properties);

      // set layer tiles
      float col = 0, row = 0, id = 0;
      while (tmxTile) {
        // create new tile
        Tile *tile = new Tile();

        int tileId;
        if (getAttribute(tmxTile, "gid")) {
          tileId = stoi(attribute) - firstTileId;
        } else {
          getError("Parse error: tile gid not found.");
          return;
        }
        
        if (tileId >= 0) {
          // set tile id
          tile->setId(id);
          id += 1;
          // set tile position
          tile->setPosition(col * scene->getTileSize().x, 
                            row * scene->getTileSize().y);
          // set tile texture rect 
          tile->addTileRect(subRects[tileId]);
          // set tileset texture
          tile->setTilesetTexture(scene->getTilesetTexture());
          // set tile opacity
          tile->setOpacity(opacity);
          // add tile to tiles layer
          tileLayer->addTile(tile);
        } else {
          delete tile;
        }

        col++;
        if (col >= layerWidth) {
          col = 0;
          row++;
        }

        tmxTile = tmxTile->NextSiblingElement("tile");
      }
  
      // add tiles layer to scene
      scene->addTileLayer(tileLayer);

      tmxTileLayer = tmxTileLayer->NextSiblingElement("layer");
    }
  }
}


// layers contain objects
void TmxParser::setSceneObjectLayers() {
  if (!isError) {
    XMLElement *tmxObjectLayer = tmxScene->FirstChildElement("objectgroup");
    while (tmxObjectLayer) {
      // create new objects layer
      ObjectLayer *objectLayer = new ObjectLayer();

      // set layer opacity
      Uint8 opacity = 255;
      if (getAttribute(tmxObjectLayer, "opacity"))
        opacity *= stof(attribute);
      objectLayer->setOpacity(opacity);

      // set layer name
      if (getAttribute(tmxObjectLayer, "name"))
        objectLayer->setName(attribute);

      // set layer visible
      if (getAttribute(tmxObjectLayer, "visible"))
        objectLayer->setVisible(static_cast<bool>(stoi(attribute)));

      // set layer properties
      if (getProperties(tmxObjectLayer))
        objectLayer->addProperties(properties);

      // set layer objects
      XMLElement *tmxObject = tmxObjectLayer->FirstChildElement("object");
      while (tmxObject) {
        // create new object
        Object *object = new Object();

        int tileId;
        if (getAttribute(tmxObject, "gid")) {
          tileId = stoi(attribute) - firstTileId;
        } else {
          getError("Parse error: object gid not found.");
          return;
        }

        // find object by tileId
        bool find = false;
        for (Object *obj : objectsList) {
          if (tileId == obj->getId()) {
            obj->copyTo(object);
            find = true;
            break;
          }
        }
        if (!find) {
          object->addTileRect(make_pair(subRects[tileId], 0));
          object->setTilesetTexture(scene->getTilesetTexture());
        }

        // set object id
        int objectId = 0;
        if (getAttribute(tmxObject, "id")) {
          objectId = stoi(attribute);
        } else {
          getError("Parse error: object y pos not found.");
          return;
        }
        object->setId(objectId);

        // set object position
        float x, y, height = 0, angle = 0;
        if (getAttribute(tmxObject, "height")) {
          height = stof(attribute);
        } else {
          getError("Parse error: object height not found.");
          return;
        }
        if (getAttribute(tmxObject, "x")) {
          x = stof(attribute);
        } else {
          getError("Parse error: object x pos not found.");
          return;
        }
        if (getAttribute(tmxObject, "y")) {
          y = stof(attribute) - height;
        } else {
          getError("Parse error: object y pos not found.");
          return;
        }
        if (getAttribute(tmxObject, "rotation"))
          angle = stof(attribute);
        object->setPosition(x, y);
        object->setRotation(angle);

        // set object name
        if (getAttribute(tmxObject, "name"))
          object->setName(attribute);
        
        // set object type
        if (getAttribute(tmxObject, "type"))
          object->setType(attribute);
        
        // set object properties
        if (getProperties(tmxObject))
            object->addProperties(properties);

        // add object to objects layer
        objectLayer->addObject(object);

        tmxObject = tmxObject->NextSiblingElement("object");
      }

      // add objects layer to scene
      scene->addObjectLayer(objectLayer);

      tmxObjectLayer = tmxObjectLayer->NextSiblingElement("objectgroup");
    }
  }
}
