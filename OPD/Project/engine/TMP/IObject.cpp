#include "Object.hpp"

using namespace engine;


Object::Object() {}


Object::~Object() {}

// ----------------------------------------------------------------------------

void Object::setSprite(sf::Sprite sprite) {
  object = &sprite;
}


void Object::setName(const std::string &name) {
  this->name = name;
}


void Object::setType(const std::string &type) {
  this->type = type;
}


void Object::setRect(sf::FloatRect objectRect) {
  textureRect = objectRect;
}


void Object::setProperties(std::map<std::string, std::string> properties) {
  this->properties = properties;
}
