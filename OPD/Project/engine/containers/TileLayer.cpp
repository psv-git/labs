#include "TileLayer.hpp"

using namespace engine;


TileLayer::TileLayer() {
  visible = true;
  opacity = 255;
}


TileLayer::~TileLayer() {
  deleteData();
}

// ============================================================================

// delete layer tiles
void TileLayer::deleteData() {
  for(Tile *tile : tilesList)
    delete tile;
}

// draw =======================================================================

void TileLayer::draw(RenderTarget &window) const {
  if (visible) {
    for (Tile *tile : tilesList)
      window.draw(*tile);
  }
}

// getters ====================================================================

const string& TileLayer::getName() {
  return name;
}


Uint8 TileLayer::getOpacity() {
  return opacity;
}

// setters ====================================================================

void TileLayer::setVisible(bool value) {
  visible = value;
}


void TileLayer::setName(const string &value) {
  name = value;
}


void TileLayer::setOpacity(Uint8 value) {
  opacity = value;
}


void TileLayer::addProperties(const map<string, string> &value) {
  for (const auto &elem : value)
    properties.insert(elem);
}


void TileLayer::addTile(Tile *tile) {
  tilesList.push_back(tile);
}
