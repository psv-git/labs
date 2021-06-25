// #include "Circle.hpp"

// using namespace engine;


// Circle::Circle(CoreManager *coreManager, float radius, 
//               std::size_t pointCount) {
//   object = new sf::CircleShape(radius, pointCount);
//   setOrigin(sf::Vector2f(radius, radius));

//   this->coreManager = coreManager;
//   coreManager->addObject(this, layer);
//   coreManager->addObject(this);
// }


// Circle::~Circle() {
//   if (object)
//     delete object;

//   coreManager->deleteObject(this);
//   coreManager->deleteObject(this, layer);

//   std::cout << "Object has ben deleted." << std::endl;
// }

// // EVENTS =====================================================================

// void Circle::onKeyPressed() {
//   if (isInteractive) {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//       move(sf::Vector2f(-5, 0));
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//       move(sf::Vector2f(5, 0));
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//       move(sf::Vector2f(0, -5));
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//       move(sf::Vector2f(0, 5));
//     std::cout << "x: " << getPosition().x << "  y: " 
//               << getPosition().y << std::endl;
//   }  
// }
