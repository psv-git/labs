#include "Scene.hpp"

using namespace engine;


Scene::Scene() {
  firstFreeId = 0;
  tileWidth = 0;
  tileHeight = 0;
  widthTilesCount = 0;
  heightTilesCount = 0;
}


Scene::~Scene() {
  deleteData();
}

// ============================================================================

// delete scene layers and objects
void Scene::deleteData() {
  for (Object *object : objectsList)
    delete object;
  for (TileLayer *layer : tileLayersList)
    delete layer;
  for (ObjectLayer *layer : objectLayersList)
    delete layer;
}

// getters ====================================================================

vector<TileLayer*>* Scene::getSceneTileLayers() {
  return &tileLayersList;
}

vector<ObjectLayer*>* Scene::getSceneObjectLayers() {
  return &objectLayersList;
}


const string& Scene::getName() {
  return name;
}


Vector2f Scene::getSize() {
  return Vector2f(static_cast<float>(tileWidth * widthTilesCount),                           static_cast<float>(tileHeight * heightTilesCount));
}


Vector2i Scene::getTileSize() {
  return Vector2i(tileWidth, tileHeight);
}


Vector2i Scene::getTilesCount() {
  return Vector2i(widthTilesCount, heightTilesCount);
}


const Texture& Scene::getTilesetTexture() {
  return tilesetTexture;
}

// setters ====================================================================

void Scene::setName(const string &value) {
  name = value;
}


void Scene::setTileSize(int width, int height) {
  tileWidth = width;
  tileHeight = height;
}


void Scene::setTilesCount(int width, int height) {
  widthTilesCount = width;
  heightTilesCount = height;
}


void Scene::setTilesetTexture(const Texture &value) {
  tilesetTexture = value;
}


void Scene::setFirstFreeId(int value) {
  firstFreeId = value;
}


void Scene::setBackgroundColor(const Color &value) {
  backgroundColor = value;
}


void Scene::addProperties(const map<string, string> &value) {
  for (const auto &elem : value)
    properties.insert(elem);
}


void Scene::addObject(Object *object) {
  objectsList.push_back(object);
}


void Scene::addTileLayer(TileLayer *layer) {
  tileLayersList.push_back(layer);
}


void Scene::addObjectLayer(ObjectLayer *layer) {
  objectLayersList.push_back(layer);
}
