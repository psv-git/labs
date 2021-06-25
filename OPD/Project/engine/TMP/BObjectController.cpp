// #include "AObject.hpp"

// using namespace engine;


// AObject::AObject() {
//   isVisible = true;
//   isInteractive = true;
//   isMovable = true;
//   isScalable = true;
//   object = nullptr;
// }


// AObject::~AObject() {
//   if (object)
//     delete object;
// }

// // DRAW =======================================================================

// void AObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//   if (isVisible) {
//     const sf::FloatRect viewportRect = target.getView().getViewport();
//     states.transform *= sf::Transformable::getTransform();
//     if (viewportRect.intersects(getLocalBounds()))
//       target.draw(*object, states);
//   }
// }

// // TRANSFORM ==================================================================

// void AObject::move(const sf::Vector2f &position) {
//   if (isMovable) {
//     sf::Transformable::move(position);
//   }
// }


// void AObject::rotate(float angle) {
//   if (isMovable) {
//     sf::Transformable::rotate(angle);
//   }
// }


// void AObject::scale(const sf::Vector2f &factor) {
//   if (isScalable) {
//     sf::Transformable::scale(factor);
//   }
// }

// // GET/SET ====================================================================

// sf::FloatRect AObject::getLocalBounds() {
//   return sf::FloatRect(0.f, 0.f, std::abs(textureRect.width), 
//                                 std::abs(textureRect.height));
// }


// sf::FloatRect AObject::getGlobalBounds() {
//   return getTransform().transformRect(getLocalBounds());
// }
