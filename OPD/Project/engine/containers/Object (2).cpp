#include "Object.hpp"

using namespace engine;


Object::Object() {
  id = 0;
  movable = false;
  gravity = 0;
  position.x = 0;
  position.y = 0;
  rotation = 0;
  visible = true;
  opacity = 255;
  tilesetTexture = nullptr;
}


Object::~Object() {}

// draw =======================================================================

void Object::draw(RenderTarget &target, RenderStates states) const {
  if (visible && tilesetTexture) {
    const FloatRect viewportRect = target.getView().getViewport();
    if (viewportRect.intersects(getLocalBounds())) {
      states.transform *= transform;
      states.texture = tilesetTexture;
      target.draw(vertices, 4, TriangleStrip, states);
    }
  }
}


void Object::changeTileRect(int index) {
  tileRect = tilesRectList[index].first;
  updatePositions();
  updateTexCoords();
}


void Object::updatePositions() {
  FloatRect bounds = getLocalBounds();
  
  vertices[0].position = Vector2f(0, 0);
  vertices[1].position = Vector2f(0, bounds.height);
  vertices[2].position = Vector2f(bounds.width, 0);
  vertices[3].position = Vector2f(bounds.width, bounds.height);
}


void Object::updateTexCoords() {
  float left = static_cast<float>(tileRect.left);
  float right = left + tileRect.width;
  float top = static_cast<float>(tileRect.top);
  float bottom = top + tileRect.height;

  vertices[0].texCoords = Vector2f(left, top);
  vertices[1].texCoords = Vector2f(left, bottom);
  vertices[2].texCoords = Vector2f(right, top);
  vertices[3].texCoords = Vector2f(right, bottom);
}

// ============================================================================

// copy this object to other object
void Object::copyTo(Object *object) {
  object->setId(id);
  object->setName(name);
  object->setType(type);
  object->setMovable(movable);
  object->setGravity(gravity);
  object->setPosition(position);
  object->setRotation(rotation);
  object->setVisible(visible);
  object->setOpacity(opacity);
  for (const auto &rect : tilesRectList)
    object->addTileRect(rect);
  object->setTilesetTexture(*tilesetTexture);
  object->addProperties(properties);
}

// getters ====================================================================

int Object::getId() {
  return id;
}


const string& Object::getName() {
  return name;
}


const string& Object::getType() {
  return type;
}


const Transform& Object::getTransform() {
  return transform;
}


FloatRect Object::getLocalBounds() const {
  float width = abs(tileRect.width);
  float height = abs(tileRect.height);

  return FloatRect(0, 0, width, height);
}


FloatRect Object::getGlobalBounds() const {
  return transform.transformRect(getLocalBounds());
}

// setters ====================================================================

void Object::setId(int value) {
  id = value;
}


void Object::setName(const string &value) {
  name = value;
}


void Object::setType(const string &value) {
  type = value;
}

// ----------------------------------------------------------------------------

void Object::setMovable(bool value) {
  movable = value;
}


void Object::setGravity(Uint8 value) {
  gravity = value;
}


void Object::setPosition(float x, float y) {
  position.x = x;
  position.y = y;
  transform.translate(x, y);
}

void Object::setPosition(const Vector2f &value) {
  setPosition(value.x, value.y);
}


void Object::setRotation(float value) {
  rotation = value;
  transform.rotate(value);
}

void Object::setTransform(const Transform &value) {
  transform = value;
}

// ----------------------------------------------------------------------------

void Object::setVisible(bool value) {
  visible = value;
}


void Object::setOpacity(Uint8 value) {
  opacity = value;
}


void Object::addTileRect(const pair<IntRect, float> &value) {
  tilesRectList.push_back(value);
  changeTileRect(0);
}


void Object::setTilesetTexture(const Texture &value) {
  tilesetTexture = &value;
}

// ----------------------------------------------------------------------------

void Object::addProperties(const map<string, string> &value) {
  for (const auto &elem : value)
    properties.insert(elem);
}
