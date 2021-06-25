#include "Tile.hpp"

using namespace engine;


Tile::Tile() {
  id = 0;
  visible = true;
  opacity = 255;
  tilesetTexture = nullptr;
}


Tile::~Tile() {}

// draw =======================================================================

void Tile::draw(RenderTarget &target, RenderStates states) const {
  if (visible && tilesetTexture) {
    const FloatRect viewportRect = target.getView().getViewport();
    if (viewportRect.intersects(getLocalBounds())) {
      states.transform *= transform;
      states.texture = tilesetTexture;
      target.draw(vertices, 4, TriangleStrip, states);
    }
  }
}


void Tile::updatePositions() {
  FloatRect bounds = getLocalBounds();
  
  vertices[0].position = Vector2f(0, 0);
  vertices[1].position = Vector2f(0, bounds.height);
  vertices[2].position = Vector2f(bounds.width, 0);
  vertices[3].position = Vector2f(bounds.width, bounds.height);
}


void Tile::updateTexCoords() {
  float left = static_cast<float>(tileRect.left);
  float right = left + tileRect.width;
  float top = static_cast<float>(tileRect.top);
  float bottom = top + tileRect.height;

  vertices[0].texCoords = Vector2f(left, top);
  vertices[1].texCoords = Vector2f(left, bottom);
  vertices[2].texCoords = Vector2f(right, top);
  vertices[3].texCoords = Vector2f(right, bottom);
}

// getters ====================================================================

int Tile::getId() {
  return id;
}


FloatRect Tile::getLocalBounds() const {
  float width = static_cast<float>(abs(tileRect.width));
  float height = static_cast<float>(abs(tileRect.height));

  return FloatRect(0, 0, width, height);
}


FloatRect Tile::getGlobalBounds() const {
  return transform.transformRect(getLocalBounds());
}

// setters ====================================================================

void Tile::setId(int value) {
  id = value;
}


void Tile::setPosition(float x, float y) {
  transform.translate(x, y);
}


void Tile::addTileRect(const IntRect &value) {
  tileRect = value;
  updatePositions();
  updateTexCoords();
}


void Tile::setTilesetTexture(const Texture &value) {
  tilesetTexture = &value;
}


void Tile::setVisible(bool value) {
  visible = value;
}


void Tile::setOpacity(Uint8 value) {
  opacity = value;
}
